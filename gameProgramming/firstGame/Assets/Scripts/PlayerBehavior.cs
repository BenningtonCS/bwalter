using UnityEngine;
using System.Collections;

public class PlayerBehavior : MonoBehaviour {

	Rigidbody rbody;

	public int speed = 2;
	public float x = 0;		// movement in x
	public float z = 0;		// movement in y
	
	private int score = 0;

	// Use this for initialization
	void Start () {
		rbody = GetComponent<Rigidbody> ();
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
		Debug.Log("Player score: " + score);
	}
}
