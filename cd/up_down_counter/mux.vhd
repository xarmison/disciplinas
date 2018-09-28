library IEEE;
use IEEE.std_logic_1164.all;

entity mux2x1_3b is 
	port (
		mais_um  : in std_logic_vector(2 downto 0);
		menos_um : in std_logic_vector(2 downto 0);
		s		 	: in std_logic;
		saida    : out std_logic_vector(2 downto 0)
	);
end mux2x1_3b; 

architecture ckt of mux2x1_3b is 
begin
	saida <= mais_um when s = '0' else menos_um;
end ckt;



