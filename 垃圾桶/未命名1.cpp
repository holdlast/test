class Father {

public:

  virtual void function() const = 0;

};

class Child : public Father {

public:

Child(unsigned int data)

   : data(data) {}

  void function() const;

  //data

private:

  int data;

};
void Child::function() const
{
	
} 
int main() {

  Child m_child(3);

  return 0;

}
