--- datapath for microprocessor
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity alu is
  port ( 
		rst   	: in STD_LOGIC;
      clk 		: in STD_LOGIC;  
      imm   	: in std_logic_vector(3 downto 0);        
		alu_Reg	: in std_logic_vector(3 downto 0);  -- input vem do Registrador
		alu_Acc 	: in std_logic_vector(3 downto 0); -- input vem do Accumulator 
		alu_mode : in std_logic_vector(2 downto 0); -- modo de seleção da alu
		output	: out STD_LOGIC_VECTOR (3 downto 0) -- output da alu 
   );
end alu;

architecture bhv of alu is
begin
	process (rst,clk,alu_mode)
	begin
	  -- take care of rst state
	  if(rst='1') then 
			output<="0000";
		elsif(clk'event AND clk='1') then
		  case(alu_mode) is
			  when "000" =>
				output <= alu_Reg;
			  
			  when "001" =>
				output <= alu_Acc; -- valor do acumulador nao muda neste modo 
			  
			  when "010" =>
				output <= imm;
				
			  when "011" =>
				output <= unsigned(alu_Acc) + unsigned(alu_Reg);
			  
			  when "100" =>
				output <= unsigned(alu_Acc) - unsigned(alu_Reg);
			  
			  when "101" =>
				output <= alu_Acc AND alu_Reg;
			  
			  when "110" =>
				output <= alu_Acc OR alu_Reg;
			  
			  when "111" =>
				output <= NOT(alu_Acc);
		  end case;
	  end if;
	end process;

end bhv;

-- *************************************************************************
-- The following is code for an accumulator. you need to figure out
-- the interconnections to the datapath
-- *************************************************************************
library IEEE;
use IEEE.std_logic_1164.all;

entity acc is
  port ( rst   : in STD_LOGIC;
         clk   : in STD_LOGIC;
         input : in STD_LOGIC_VECTOR (3 downto 0);
         enb   : in STD_LOGIC;
         output: out STD_LOGIC_VECTOR (3 downto 0)
       );
end acc;

architecture bhv of acc is
signal temp : STD_LOGIC_VECTOR(3 downto 0);
begin
	process (rst, input, enb, clk)
	begin
		if (rst = '1') then
			output <= "0000";
		elsif (clk'event and clk = '1') then
				if (enb = '1') then 
					output <= input;
					temp <= input;
				else
					output <= temp;
				end if;
		end if;
	end process;
end bhv;

-- ***********************************************************************
-- the following is code for a register file. you may use your own design.
-- you also need to figure out how to connect this inyour datapath.

-- the way the rf works is: it 1st checks for the enable, then checks to
-- see which register is selected and outputs the input into the file. 
-- otherwise, the output will be whatever is stored in the selected register.
-- ***********************************************************************
library IEEE;
use IEEE.std_logic_1164.all;

entity rf is
  port ( rst    : in STD_LOGIC;
         clk    : in STD_LOGIC;
         input  : in std_logic_vector(3 downto 0);
         sel    : in std_logic_vector(1 downto 0);
         enb    : in std_logic;
         output : out std_logic_vector(3 downto 0)
       );
		
end rf;

architecture bhv of rf is
signal out0, out1, out2, out3 : std_logic_vector(3 downto 0);
begin
	process (rst, clk,enb,sel)
	begin
	
	  -- take care of rst state
	  if(rst='1') then
	  out0<= "0000";
	  out1<= "0000";
	  out2<= "0000";
	  out3<= "0000";

     elsif(clk'event and clk = '1') then
		 if enb = '0' then
			case (sel) is
			  when "00" => 
				 out0 <= input;
			  when "01" => 
				 out1<= input;
				 
			  when "10" => 
				 out2<= input;
				 
			  when "11" =>
				 out3<= input;
				 
			  when others =>
			end case;
		 else
			case (sel) is
			  when "00" =>
				 output <= out0;
			  when "01" =>
				 output <= out1;
			  when "10" =>
				 output <= out2;
			  when "11" =>
				 output <= out3;
			  when others =>
			end case;
		end if;
		 end if;
	end process;	
end bhv;

library IEEE;
use IEEE.std_logic_1164.all;
-- entradas da dp precisam vir do bloco de controle
entity dp is
  port ( rst     : in STD_LOGIC;
         clk     : in STD_LOGIC;
         imm     : in std_logic_vector(3 downto 0); 
			alu_mode : in std_logic_vector(2 downto 0);
			RF_sel : in std_logic_vector(1 downto 0);
			RF_enb : in std_logic;
			acc_enb : in std_logic;
         output_4: out STD_LOGIC_VECTOR (3 downto 0)
      );
end dp;

architecture rtl2 of dp is

	component alu is
	  port ( rst   : in STD_LOGIC;
				clk   : in STD_LOGIC;
				imm   : in std_logic_vector(3 downto 0);        
				alu_Reg: in std_logic_vector(3 downto 0);  -- input vem do Registrador
				alu_Acc : in std_logic_vector(3 downto 0); -- input vem do Accumulator 
				alu_mode : in std_logic_vector(2 downto 0); -- modo de seleção da alu
				output: out STD_LOGIC_VECTOR (3 downto 0) -- output da alu 
			);
	end component;

	component acc is 
	 port (rst   : in STD_LOGIC;
				clk   : in STD_LOGIC;
				input : in STD_LOGIC_VECTOR (3 downto 0); -- input do accumulator vem da alu
				enb   : in STD_LOGIC; -- enable 
				output: out std_logic_vector(3 downto 0)
				);
	end component;
	component rf is
	 port ( rst    : in STD_LOGIC;
				clk    : in STD_LOGIC;
				input  : in std_logic_vector(3 downto 0); -- input do banco de reg vem do accumulator
				sel    : in std_logic_vector(1 downto 0); -- modo de seleção de qual registrador será utilizado
				enb    : in std_logic; -- enable : define se serão armazenados novos dados ou dados serão lidos
				output : out std_logic_vector(3 downto 0) -- output vem de um dos registradores
			 );
	end component;		

	signal alu_out: std_logic_vector(3 downto 0);
	signal acc_out : std_logic_vector(3 downto 0);
	signal rf_out : std_logic_vector(3 downto 0);

begin

	alu1: alu port map (rst,clk,imm,rf_out,acc_out,alu_mode,alu_out);
	acc1: acc port map (rst, clk, alu_out, acc_enb, acc_out);
	bancodereg: rf port map(rst,clk,acc_out,RF_sel,RF_enb,rf_out);

	process (rst, clk)
		begin
			if(rst='1') then 
				output_4 <= "0000";
			
			elsif(clk'event AND clk='1') then
				output_4 <= acc_out;
		   end if;
		
   end process;
end rtl2;