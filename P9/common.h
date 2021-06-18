using namespace std;

// Named constants for number of positions on each wheel and number of wheels
const int WHEEL_POSITIONS = 30;
const int NUM_WHEELS = 3;

//Globally declared struct for slot wheels
struct wheel
{
    char symbols[WHEEL_POSITIONS+1];
    int spinPos;
    char spinSymbol;
};

// Globally declared constant for slot wheel initialization
const char wheelSymbols[] = "-X-X-X-X-X=X=X=X=X*X*X*X@X@X7X";

// Globally declared constant for the scale of spin position
const int SCALE = 30;
