using UnityEngine;
using System.Collections;

public class Board : MonoBehaviour {

	public GameObject boxPrefab;
	public int numBombs = 20;

	// declare size of board
	private static int rows = 10;
	private static int columns = 10;

	// 2d array of the positions of each box
	private Vector2[,] boxPositions = new Vector2[rows, columns];
	// 2d array to hold the box game objects
	private GameObject[,] boxGO = new GameObject[rows, columns];
	// 2d array to hold locations of each bomb on the board
	private int[,] bombs = new int[rows, columns];


	// Use this for initialization
	void Start () {

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
			bombs[r, c] = 1;
		}

		// initialize the board
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
							break;
						// check each square around self for a bomb
						if (bombs[r+i, c+j] == 1)
							// increase count for each bomb found
							boxGO[r,c].GetComponent<Boxes>().adjacentBombs++;
					}
				}
			}
		}

	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
