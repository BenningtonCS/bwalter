using UnityEngine;
using System.Collections;

public class Movement : MonoBehaviour {

	public int speed = 2;
	public float x = 0;
	public float z = 0;

	// Use this for initialization
	void Start () {

	}

	void FixedUpdate() {
		Rigidbody rigidbody = GetComponent<Rigidbody> ();
		x = Input.GetAxis ("Horizontal");
		z = Input.GetAxis ("Vertical");
		rigidbody.AddForce (new Vector3(x * speed, 0, z * speed));
	}

	// Update is called once per frame
	void Update () {
		/*
		if (Input.GetKey (KeyCode.UpArrow)) {
			transform.Translate(Vector3.forward*Time.deltaTime*speed);
		}
		if (Input.GetKey (KeyCode.DownArrow)) {
			transform.Translate(Vector3.back*Time.deltaTime*speed);
		}
		if (Input.GetKey (KeyCode.LeftArrow)) {
			transform.Translate(Vector3.left*Time.deltaTime*speed);
		}
		if (Input.GetKey (KeyCode.RightArrow)) {
			transform.Translate(Vector3.right*Time.deltaTime*speed);
		}
		*/
	}

	void OnTriggerEnter(Collider coll) {
		coll.gameObject.SetActive (false);
	}
}
