int main(void)
{
  bool F;
  bool X0 = 0,X1 = 0,Y0 = 0,Y1 = 0;

  DDRD |=0b00000000; // declares the inputs as 2,3,6,7
  DDRB = (1<<PINB5); // declared 13 pin as output
  PORTD |= 0b11001100; // pullup inputs

  while(1)
  {
    X0 = (PIND & (1<<PIND3)) == (1<<PIND3);
    X1 = (PIND & (1<<PIND2)) == (1<<PIND2);
    Y0 = (PIND & (1<<PIND7)) == (1<<PIND7);
    Y1 = (PIND & (1<<PIND6)) == (1<<PIND6);

    F = (X1&!Y1) | (X1&X0&!Y0) | (X0&!Y0&!Y1);

    if(F)
    {
      PORTB = (1<<PINB5);
    }

    else
    {
      PORTB = !(1<<PINB5);
    }
  }
  return 0;
}
