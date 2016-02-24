using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class Boxes : MonoBehaviour {

	public bool isBomb;					// is it a bomb?
	public bool isFlagged = false;		// has the player set a flag?

	public int adjacentBombs = 0;
	public GameObject numBombsPrefab;	// text to display adjacentBombs
	public GameObject board;

	private Collider boxCollider;


	// set a flag
	public void setFlag() {
		isFlagged = true;
		GetComponent<Renderer>().material.SetColor("_Color", Color.cyan);
		
		board.GetComponent<Board>().numBombs--;
		if (isBomb) board.GetComponent<Board>().numBombsFlagged++;
	}

	// remove a flag
	public void removeFlag() {
		isFlagged = false;
		GetComponent<Renderer>().material.SetColor("_Color", Color.white);

		board.GetComponent<Board>().numBombs++;
	if (isBomb) board.GetComponent<Board>().numBombsFlagged--;
	}

	// blow up the box and end the game
	public void blowUp() {
		GetComponent<Renderer>().material.SetColor("_Color", Color.red);
		board.GetComponent<Board>().gameLost = true;
	}

	// clear the box from the game
	public void clear() {
		boxCollider.gameObject.SetActive(false);
		numBombsPrefab = (GameObject)Instantiate(numBombsPrefab, this.transform.position, Quaternion.identity);
		numBombsPrefab.GetComponent<TextMesh>().text = adjacentBombs.ToString();
		board.GetComponent<Board>().numBoxesCleared++;
	}

	// called when the player left clicks on a box to remove it
	void onLeftClick() {
		Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
		RaycastHit hit;

		// check which box was hit
		if (Physics.Raycast(ray, out hit)) {
			if (hit.collider == boxCollider) {
				if (isBomb && !isFlagged) blowUp();		
				else if (!isBomb && !isFlagged) clear();
			}
		}
	}

	// called when the player right clicks on a box to add or remove a flag
	void onRightClick() {
		Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
		RaycastHit hit;

		// check which box was hit
		if (Physics.Raycast(ray, out hit)) {
			if (hit.collider == boxCollider) {
				if (isFlagged) removeFlag();
				else if (!isFlagged) setFlag();
			}
		}
	}

	
	// Use this for initialization
	void Start () {
		boxCollider = GetComponent<Collider>();
		board = GameObject.FindWithTag("Board");
	}

	// Update is called once per frame
	void Update () {
		if (Input.GetMouseButtonDown(0)) onLeftClick();
		if (Input.GetMouseButtonDown(1)) onRightClick();
	}
}
