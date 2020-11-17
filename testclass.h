#ifndef TESTCLASS_H
#define TESTCLASS_H

class TestClass {

	public:

		void runTests();

	private:

		void printer(std::string message, bool condition, bool expectedOutcome);
		void testNavigation_executeMovement_shouldReachDestination();
		void testHittingWall_executeMovement_shouldHitWall();
		void testHittingWall_executeMovement_shouldNotHitWall();

};

#endif
