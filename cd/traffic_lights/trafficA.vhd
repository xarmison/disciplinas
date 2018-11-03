library IEEE;
use IEEE.std_logic_1164.all;

entity trafficA is
  port (
    clk, clr : in std_logic;
    lights   : out std_logic_vector(5 downto 0) 
  );
end trafficA;

architecture ckt of trafficA is

  type state_type is (s0, s1, s2, s3, s4, s5);
  
  signal state : state_type;
  signal count : std_logic_vector(5 downto 0);

  constant SEC20 : std_logic_vector(5 downto 0) := "10100";
  constant SEC3  : std_logic_vector(5 downto 0) := "00011";
  constant SEC1  : std_logic_vector(5 downto 0) := "00001";

begin

  process(clk, clr) begin
    if clr = '1' then 
      state <= s0;
      count <= X"0";

    elsif clk = '1' and clk'event then
      case state is 
        when s0 => 
          if count < SEC20 then 
            state <= s0;
            count <= count + 1;
          else
            state <= s1;
            count <= X"0";
          end if;

        when s1 => 
          if count < SEC3 then
            state <= s1;
            count <= count + 1;
          else 
            state <= s2;
            count <= X"0";
          end if;

        when s2 => 
            if count < SEC1 then 
              state <= s2;
              count <= count + 1;
            else 
              state <= s3;
              count <= X"0";
            end if;
        
        when s3 => 
          if count < SEC20 then 
            state <= s3;
            count <= count + 1;
          else
            state <= s4;
            count <= X"0";
          end if;
        
        when s4 => 
          if count < SEC3 then
            state <= s4;
            count <= count + 1;
          else 
            state <= s5;
            count <= X"0";
          end if;
      
        when s5 => 
          if count < SEC1 then 
            state <= s5;
            count <= count + 1;
          else 
            state <= s0;
            count <= X"0";
          end if;
        
        when others =>
          state <= s0;
      
      end case;
    end if;
  end process;
  
  process(state) begin
    case state is 
      when s0 => lights <= "100001";
      when s1 => lights <= "100010";
      when s2 => lights <= "100100";
      when s3 => lights <= "001100";
      when s4 => lights <= "010100";
      when s5 => lights <= "100100";
      when others => lights <= "100001";
    end case;
  end process;
end ckt; 