#include <iostream>
#include <math.h>

using namespace std;


class Body {
	private:
		double mass;
		double velocity;
		double position;
	
	public:
		
		void newBody(double m, double v, double p) {
			mass = m;
			velocity = v;
			position = p;
		}

		void move(double force, double time) {

			cout << "A force " << force << "N is applied to Object of mass " << mass << "kg. It moved from " << position;
			
			double acceleration = force / mass;	
			position = velocity * time + 0.5 * acceleration * pow(time, 2);
			
			cout << " to " << position << "m"<<endl;
		}
};

int main(void) {
	Body body;
	body.newBody(10, 0, 0);

	body.move(8.10, 5.21);
}
