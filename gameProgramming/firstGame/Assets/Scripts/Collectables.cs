using UnityEngine;
using System.Collections;

public class Collectables : MonoBehaviour {

	public GameObject prefab;
	public int numObjects = 5;
	
	// size of map in x and z
	public int gridX = 9;	
	public int gridZ = 9;
	
	/*
		Parameters: integers for the minimum and maxium range
		Returns: a random integer
		Generates a random number between min and max
	*/
	private int randNumber(int min, int max) {
		int num = Random.Range(min, max);
		return num;
	}

	// Use this for initialization
	void Start () {
	
		// randomly place collectables on the map
		for (int i=0;i<numObjects;i++) {
			Vector3 pos = new Vector3(randNumber(-gridX, gridX), 0, randNumber(-gridZ, gridZ));
			Instantiate(prefab, pos, Quaternion.identity);
		}
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
