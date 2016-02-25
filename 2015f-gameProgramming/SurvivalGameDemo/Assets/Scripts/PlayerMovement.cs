using UnityEngine;
using System.Collections;

public class PlayerMovement : MonoBehaviour {


	public float movementSpeed = 1f;
	public float turnSpeed = 100f;

	Rigidbody playerRigidbody;
	Animator playerAnimator;

	// Use this for initialization
	void Start () {
		playerRigidbody = GetComponent<Rigidbody>();
		playerAnimator = GetComponent<Animator>();
	}
	
	// Update is called once per frame
	void Update () {
		float forwardMovement = Input.GetAxis("Vertical");
		float turnMovement = Input.GetAxis("Horizontal");	
		
		
		if (forwardMovement == 0 && turnMovement == 0) {
			playerAnimator.SetBool("isWalking", false);
		} else {
			playerAnimator.SetBool("isWalking", true);
		}
			
		// make the player move forward in the direction he's facing
		Vector3 movement = forwardMovement * transform.forward;
		movement = movement.normalized * Time.deltaTime * movementSpeed;
		playerRigidbody.MovePosition(transform.position + movement);
		
		// grab the current angle of the player
		float currAngle = transform.rotation.eulerAngles.y;
		// get where the player wants to turn the player
		float targetAngle = currAngle + turnMovement * Time.deltaTime * turnSpeed;
		// transform the euler angle to a quaternion (pitch, yaw, etc.)
		Quaternion newRotation = Quaternion.Euler(new Vector3(0, targetAngle,0));
		// rotate the player
		playerRigidbody.MoveRotation(newRotation);
	}
}
