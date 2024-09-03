class SimpleClass {
 private:
  double _value;

 public:
  SimpleClass(double value);
  SimpleClass();
  ~SimpleClass();
  void setValue(double _value);
  double getValue();
  double add(double value);
};