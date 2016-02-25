using UnityEngine;
using System.Collections;

public class playerAttack : MonoBehaviour {

	public float timeBetweenBullets = 0.15f;

	LineRenderer bulletLine;
	AudioSource gunSound;
	Ray shootRay;
	float timer;	// timer will keep track of time between bullets

	// Use this for initialization
	void Start () {
		bulletLine = GetComponent<LineRenderer>();
		gunSound = GetComponent<AudioSource>();
		timer = 0f;
	}
	
	// Update is called once per frame
	void Update () {
		timer += Time.deltaTime;
		if (timer >= timeBetweenBullets && Input.GetButton("Fire")) {
			Shoot();
		} else {
			DisableEffects();
		}
	}
	
	void DisableEffects() {
		bulletLine.enabled = false;
	}
	
	void Shoot() {
		timer = 0f;		// reset timer
		
		gunSound.Play();
	
		bulletLine.enabled = true;
		shootRay.origin = transform.position;
		shootRay.direction = transform.forward;
		
		RaycastHit shootHit;
		
		bulletLine.SetPosition(0, transform.position);
		
		if (Physics.Raycast(shootRay, out shootHit)) {
			// enemy takes damage
			bulletLine.SetPosition(1, shootHit.point);
		} else {
			bulletLine.SetPosition(1, shootRay.origin + shootRay.direction*1000);
		}
	}
}
