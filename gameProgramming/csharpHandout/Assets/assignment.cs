﻿using UnityEngine;
using System.Collections;

public class assignment : MonoBehaviour {

	Rigidbody rbody;

	public string playerName = "Brendon";	// changed to playerName from name to fix
											// warning CS0108
	public int speed = 2;
	public float x = 0;
	public float z = 0;

	// Use this for initialization
	void Start () {
		Debug.Log ("Hello, " + playerName);
		rbody = GetComponent<Rigidbody> ();
	}

	void FixedUpdate() {
		x = Input.GetAxis ("Horizontal");
		z = Input.GetAxis ("Vertical");
		rbody.AddForce( new Vector3(x*speed, 0, z*speed));
	}

	
	// Update is called once per frame
	void Update () {
	
	}
}
