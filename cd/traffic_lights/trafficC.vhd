library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

entity trafficC is
  port (
    clk, clr : in std_logic;
    lights   : out std_logic_vector(5 downto 0) 
  );
end trafficC;

architecture ckt of trafficC is

  type state_type is (s0, s1);
  
  signal state : state_type;
  signal count : std_logic_vector(1 downto 0);

  constant SEC3  : std_logic_vector(1 downto 0) := "11";

begin

  process(clk, clr) begin
    if clr = '1' then 
      state <= s0;
      count <= "00";

    elsif clk = '1' and clk'event then
      case state is 
        when s0 => 
          if count < SEC3 then 
            state <= s0;
            count <= count + 1;
          else
            state <= s1;
            count <= "00";
          end if;

        when s1 => 
          if count < SEC3 then
            state <= s1;
            count <= count + 1;
          else 
            state <= s0;
            count <= "00";
          end if;
        
        when others =>
          state <= s0;
      
      end case;
    end if;
  end process;
  
  process(state) begin
    case state is 
      when s0 => lights <= "000000";
      when s1 => lights <= "010010";
      when others => lights <= "000000";
    end case;
  end process;
end ckt; 