library IEEE;
use IEEE.std_logic_1164.all;

entity somador is
  port (
    a, b, cin : in  std_logic;
    sum, cout : out std_logic
  );
end somador;

architecture ckt of somador is
  signal aux : std_logic_vector(2 downto 0);
begin
  aux(0) <= a xor b;
  aux(1) <= cin and aux(0);
  aux(2) <= a and b;

  sum  <= aux(0) xor cin;
  cout <= aux(1) or aux(2);

end ckt;