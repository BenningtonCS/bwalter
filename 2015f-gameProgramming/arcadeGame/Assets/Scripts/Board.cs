using UnityEngine;
using System.Collections;

public class Board : MonoBehaviour {

	public GameObject boxPrefab;
	public GameObject time;
	public GameObject numBombsLeft;
	public int numBombs = 20;
	public int numBoxesCleared = 0;
	public int numBombsFlagged = 0;		// number of bombs correctly flagged
	public float timeElapsed = 0;		// time elapsed since game start
	public bool gameLost = false;		// has the game been won?

	// declare size of board
	private static int rows = 10;
	private static int columns = 10;

	// 2d array of the positions of each box
	private Vector2[,] boxPositions = new Vector2[rows, columns];
	// 2d array to hold the box game objects
	private GameObject[,] boxGO = new GameObject[rows, columns];
	// 2d array to hold locations of each bomb on the board
	private int[,] bombs = new int[rows, columns];


	// initialize positions of the bombs
	void initBombs() {
		// initalize bomb array with a bunch of 0s
		for (int r=0;r<rows;r++) {
			for (int c=0;c<columns;c++) {
				bombs[r,c] = 0;
			}
		}

		// randomize position of bombs in the array (1 = bomb)
		for (int i=0;i<numBombs;i++) {
			int r = Random.Range(0, rows);
			int c = Random.Range(0, columns);

			// make sure bombs aren't being placed in the same square
			if (bombs[r,c] == 1) i--;
			else bombs[r, c] = 1;
		}
	}

	// initialize the board
	void initBoard() {
		for (int r=0;r<rows;r++) {
			for (int c=0;c<columns;c++) {

				// place and instantiate the boxes
				boxPositions[r,c] = new Vector2((float)(c), (float)(r));
				boxGO[r,c] = (GameObject)Instantiate(boxPrefab, boxPositions[r,c], Quaternion.identity);

				// initialize the bombs from the bomb array
				if (bombs[r,c] == 1) 
					boxGO[r,c].GetComponent<Boxes>().isBomb = true;

				// determine the number of bombs adjacent to each box
				for (int i=-1;i<=1;i++) {
					for (int j=-1;j<=1;j++) {
						// make sure it's accessing a valid index
						if (r+i < 0 || c+j < 0 || r+i >= rows || c+j >= columns)
							continue;
						// check each square around self for a bomb
						if (bombs[r+i, c+j] == 1)
							// increase count for each bomb found
							boxGO[r,c].GetComponent<Boxes>().adjacentBombs++;
					}
				}
			}
		}
	}

	// updates the timer
	void updateTimer() {
		timeElapsed += Time.deltaTime;

		float minutes = timeElapsed/60;
		float seconds = timeElapsed%60;
		float fraction = (timeElapsed*100) %100;

		time.GetComponent<TextMesh>().text = string.Format("{0:00} : {1:00} : {2:000}", minutes, seconds, fraction);
	}

	// switches to true when this is first called to keep the function being called into infinity	
	private bool onLoseCalled = false;

	// called from Boxes.cs when the player clicks on a bomb
	void onLose() {
		onLoseCalled = true;
		for (int r=0;r<rows;r++) {
			for (int c=0;c<columns;c++) {
				// blow up bombs and clear empty spaces
				if (bombs[r,c] == 1) boxGO[r,c].GetComponent<Boxes>().blowUp();
				else boxGO[r,c].GetComponent<Boxes>().clear();
			}
		}
	}

	bool checkWinCondition() {
		if ((rows*columns - numBombs) <= numBoxesCleared) return true;
		return false;
	}

	// Use this for initialization
	void Start () {
		initBombs();
		initBoard();
	}
	
	// Update is called once per frame
	void Update () {
		// if the win condition hasn't been met and the game hasn't been lost yet
		if (!checkWinCondition() && !gameLost) {
			// update time
			updateTimer();
			// check how many boxes have been flagged
			numBombsLeft.GetComponent<TextMesh>().text = numBombs.ToString();
		} else if (!onLoseCalled) onLose();
	}
}
