using UnityEngine;
using System.Collections;

public class CameraMovement : MonoBehaviour {

	public GameObject player;		// game object for the player (sphere)
	private Vector3 transOffset;	// translation offset of the camera and player

	// Use this for initialization
	void Start () {
		transOffset = transform.position;
	}
	
	// Update is called once per frame
	void Update () {

	}

	// called after Update and FixedUpdate are called
	void LateUpdate() {
		transform.position = player.transform.position + transOffset;
	}
}
