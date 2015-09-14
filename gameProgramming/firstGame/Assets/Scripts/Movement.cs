using UnityEngine;
using System.Collections;

public class Movement : MonoBehaviour {

	Rigidbody rbody;

	public int speed = 2;
	public float x = 0;
	public float z = 0;

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

	void OnTriggerEnter(Collider coll) {
		coll.gameObject.SetActive (false);
	}
}
