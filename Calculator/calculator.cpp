class Calc 
{
  public:
    Calc();
    double Number;          // Answer 
    int Operation(string);  // Work with client code 
    int stack_spot;         // Hold the spot int the stack
  private:
    double s2f(string);     // Converts from the string to double 
    double stack[3];        // Stack that holds the data 
    void Add();
    void Sub();
    void Mul();
    void Div();
    void Sqrt();
    void Equal();
    void Clear();
    double SquareRoot(double);
    double Abs(double);	
};

Calc :: Calc()
{
  stack_spot = 0;
  Number = 0;
}

int Calc :: Operation (string n)
{
  if (n == "Sqrt")
  {
  	Sqrt();
  	stack_spot = 1;
  	return -1;
  }
  else if (n == "Clear")
  {
  	Clear();
  	return -1;
  }
  else if (stack_spot == 0)
  {
  	stack[0] = s2f(n);
  	stack_spot++;
  	Number = stack[0];
  }
  else if (stack_spot == 1)
  {
  	if (n == "+")
  	  n = "1";
  	else if (n == "-")
      n = "2";
    else if (n == "*")
      n = "3";
    else if ( n == "/")
      n = "4";

    stack[stack_spot] = s2f(n);
    stack_spot++;
  }
  else if (stack_spot == 2)
  {
  	stack[2] = s2f(n);
  	Equal();
  	stack_spot = 1;
  }
}

void Calc::Sqrt()
{

}

void Calc::Clear()
{
   stack_spot = 0;
   Number = 0;
   stack[0] = 0;
}

double Calc::s2f(string str)
{
  const char* strC;
  strC = str.c_str();
  return atof(strC);
}

void Calc::Equal()
{
  if (stack[1]      1)
  	Add();
  else if(stack[1]      2)
  	Sub
}
