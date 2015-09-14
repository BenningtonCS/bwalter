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

	// Use this for initialization
	void Start () {
		rbody = GetComponent<Rigidbody> ();
		
		scoreText.text = "Score: " + score.ToString();	// start score at 0
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
		scoreText.text = "Score: " + score.ToString();
		Debug.Log("Player score: " + score);
	}
}
