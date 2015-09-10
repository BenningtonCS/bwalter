using UnityEngine;
using System.Collections;

public class assignment : MonoBehaviour {

	public string playerName = "Brendon";	// changed to playerName from name to fix
											// warning CS0108

	// Use this for initialization
	void Start () {
		Debug.Log ("Hello, " + playerName);
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
