using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class Boxes : MonoBehaviour {

	public bool isBomb;					// is it a bomb?
	public bool isFlagged = false;		// has the player set a flag?
	public bool isCleared = false;		// has the box been cleared

	public int adjacentBombs = 0;
	public GameObject numBombsPrefab;	// text to display adjacentBombs

	private Collider boxCollider;

	// Use this for initialization
	void Start () {
		boxCollider = GetComponent<Collider>();
	}

	// set a flag
	void setFlag() {
		isFlagged = true;
		GetComponent<Renderer>().material.SetColor("_Color", Color.cyan);
	}

	// remove a flag
	void removeFlag() {
		isFlagged = false;
		GetComponent<Renderer>().material.SetColor("_Color", Color.white);
	}

	// blow up the box and end the game
	void blowUp() {
		GetComponent<Renderer>().material.SetColor("_Color", Color.red);
	}

	// clear the box from the game
	void clear() {
		boxCollider.gameObject.SetActive(false);
		numBombsPrefab = (GameObject)Instantiate(numBombsPrefab, this.transform.position, Quaternion.identity);
		numBombsPrefab.GetComponent<TextMesh>().text = adjacentBombs.ToString();
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
	
	// Update is called once per frame
	void Update () {
		if (Input.GetMouseButtonDown(0)) onLeftClick();
		if (Input.GetMouseButtonDown(1)) onRightClick();
	}
}
