#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
int main() {
	//game set up (you'll need these lines in every game)
	sf::RenderWindow screen(sf::VideoMode(1200, 800), "AAAAAAAAAA"); //set up screen
	sf::Event event; //set up event queue
	sf::Clock clock; //set up the clock (needed for game timing)
	const float FPS = 60.0f; //FPS
	screen.setFramerateLimit(FPS); //set FPS

	int times = 0;
	int currTimes = 0;
	int currNum = 1;
	int prevNum = 1;
	int answer = 0;
	int x = 0;
	int y = 0;
	sf::RectangleShape rectangle(sf::Vector2f(x, y));
	cout << "How many fibonacci?" << endl;
	cin >> times;

	while (currTimes < times) {

		answer = prevNum + currNum;
		cout << prevNum << " + " << currNum << " = " << answer << endl;
		prevNum = currNum;
		currNum = answer;
		x = answer / 1.65;

		rectangle.setPosition(sf::Vector2f(x, y));
		rectangle.setFillColor(sf::Color(answer/2, answer/3, answer/5));
		rectangle.setSize(sf::Vector2f(answer, answer));
		screen.draw(rectangle);
		screen.display(); //flips memory drawings onto screen
		currTimes++;
	}

	while (true) {
		while (screen.pollEvent(event)) { //look for events-----------------------

		   //this checks if the user has clicked the little "x" button in the top right corner
			if (event.type == sf::Event::EventType::Closed)
				screen.close();

		}//end event loop---------------------------------------------------------------
	}
}