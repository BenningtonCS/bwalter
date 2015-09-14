using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class PlayerBehavior : MonoBehaviour {

	Rigidbody rbody;

	/* MOVEMENT */
	public int speed = 2;
	public float x = 0;		// movement in x
	public float z = 0;		// movement in y
	
	/* UI */
	private int score = 0;	// score holder
	public Text scoreText;	// score as shown in the UI
	public Text winText;	// text displayed when you win

	// Use this for initialization
	void Start () {
		rbody = GetComponent<Rigidbody> ();
		
		// start score at 0
		scoreText.text = "Score: " + score.ToString();
		// make it so the win text does not display at the beginning
		winText.gameObject.SetActive(false);
	}

	void FixedUpdate() {
	
		x = Input.GetAxis ("Horizontal");
		z = Input.GetAxis ("Vertical");
		rbody.velocity = new Vector3(x * speed, 0, z * speed);
	}

	// Update is called once per frame
	void Update () {

	}

	// called when the player collides with the collectables
	void OnTriggerEnter(Collider coll) {
		coll.gameObject.SetActive (false);
		score++;
		updateScore(score);
		
	}
	
	void updateScore(int nscore) {
		score = nscore;
		scoreText.text = "Score: " + score.ToString();
		
		// TODO: somehow get the number of objects from the collectables script
		// if the player collects all the objects, display the win text
		if (score == 6) winText.gameObject.SetActive(true);
	}
}
