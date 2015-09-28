using UnityEngine;
using System.Collections;

public class zombunnyMovement : MonoBehaviour {

	public float movementSpeed = 1f;
	public float turnSpeed = 100f;
	
	Rigidbody zombunnyRigidbody;
	Animator zombunnyAnimator;

	// Use this for initialization
	void Start () {
		zombunnyRigidbody = GetComponent<Rigidbody>();
		zombunnyAnimator = GetComponent<Animator>();
	}
	
	// Update is called once per frame
	void Update () {
		Vector3 movement = transform.position + transform.forward;
		movement = movement.normalized *Time.deltaTime * movementSpeed;
		zombunnyRigidbody.MovePosition(transform.position + movement);
	}
}
