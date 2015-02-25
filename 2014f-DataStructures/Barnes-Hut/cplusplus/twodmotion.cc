#include <iostream>
#include <cmath>

using namespace std;

class Body {
	private:
		double mass;
		double position[2];
		double velocity[2];

	public:
		
		void newBody(double m, double x, double y, double vx, double vy) {
			mass = m;
			position[0] = x;  position[1] = y;
			velocity[0] = vx; velocity[1] = vy;
		}

		void move(double force, double time, double theta) {
			double fx = cos(theta) * force;
			double fy = sin(theta) * force;

			double ax = fx / mass;
			double ay = fy / mass;

			position[0] = velocity[0] * time + 0.5 * ax * pow(time, 2);
			position[1] = velocity[1] * time + 0.5 * ay * pow(time, 2);

			cout << position[0] << ", " << position[1] <<endl;
		}
};

int main(void) {
	Body body;
	body.newBody(100, 0, 0, 0, 0);
	body.move(10, 2, 3.141592);
}
