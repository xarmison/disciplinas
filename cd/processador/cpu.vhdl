-- cpu (top level entity)
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity cpu is
	port (
		rst			: in STD_LOGIC;
		start			: in STD_LOGIC;
		clk			: in STD_LOGIC;
		rightDisp	: out std_logic_vector(6 downto 0); -- Display de 7 seg da esquerda
		leftDisp 	: out std_logic_vector(6 downto 0); -- Display de 7 seg da direita
		opcode1		: out std_logic_vector(6 downto 0); -- Primeiro digito do OPCODE
		opcode2		: out std_logic_vector(6 downto 0); -- Segundo digito do OPCODE
		opcode3		: out std_logic_vector(6 downto 0); -- Terceiro digito do OPCODE
		opcode4		: out std_logic_vector(6 downto 0)  -- Quarto digito do OPCODE
	);
end cpu;

architecture struc of cpu is
	component ctrl 
		port ( 
			rst			: in STD_LOGIC;
			start			: in STD_LOGIC;
			clk			: in STD_LOGIC;       
			imm			: out std_logic_vector(3 downto 0);
			modo_ALU		: out std_logic_vector(2 downto 0);
			Reg_sel		: out std_logic_vector(1 downto 0);
			Reg_enable	: out std_logic;
			acc_enb		: out std_logic;
			codigoOP		: out std_logic_vector(3 downto 0)
		);
	end component;

	component dp
		port (
			rst		: in STD_LOGIC;
			clk		: in STD_LOGIC;
			imm		: in std_logic_vector(3 downto 0);
			alu_mode	: in std_logic_vector(2 downto 0);
			RF_sel	: in std_logic_vector(1 downto 0);
			RF_enb	: in std_logic;
			acc_enb	: in std_logic;
			output_4	: out STD_LOGIC_VECTOR (3 downto 0)
		);
	end component;
	
	-- Ndisp1eros para o display de 7 segmentos
	constant disp0 : std_logic_vector(6 downto 0) := "0000001";
	constant disp1 : std_logic_vector(6 downto 0) := "1001111";
	constant disp2 : std_logic_vector(6 downto 0) := "0010010";
	constant disp3 : std_logic_vector(6 downto 0) := "0000110";
	constant disp4 : std_logic_vector(6 downto 0) := "1001100";
	constant disp5 : std_logic_vector(6 downto 0) := "0100100";
	constant disp6 : std_logic_vector(6 downto 0) := "0100000";
	constant disp7 : std_logic_vector(6 downto 0) := "0001111";
	constant disp8 : std_logic_vector(6 downto 0) := "0000000";
	constant disp9	: std_logic_vector(6 downto 0) := "0000100";
	
	constant dispOff : std_logic_vector(6 downto 0) := "1111111";
	
	signal immediate	: std_logic_vector(3 downto 0);
	signal cpu_out		: std_logic_vector(3 downto 0); -- resultado do acumulador 
	signal instrucao 	: std_logic_vector(3 downto 0); -- opcode
	signal mode_ALU	: std_logic_vector(2 downto 0); -- seleciona modo da alu
	signal sel_RF		: std_logic_vector(1 downto 0); -- seleciona disp1 dos 4 regs
	signal enb_RF		: std_logic;
	signal enb_acc 	: std_logic;
	
begin

	controller: ctrl port map(rst, start, clk,immediate,mode_ALU,sel_RF,enb_RF,enb_acc,instrucao); 
	datapath: dp port map(rst, clk, immediate, mode_ALU, sel_RF, enb_RF, enb_acc, cpu_out); 

  process(rst, clk, instrucao)
  begin

    -- take care of rst case here
	 if(rst='1') then
			-- limpa o display de segmentos
			rightDisp <= dispOff;
			
			leftDisp <= dispOff;
			
			opcode1	<= dispOff;
			opcode2	<= dispOff;
			opcode3	<= dispOff;
			opcode4	<= dispOff;

	elsif(clk'event and clk='1') then
		-- display do OPCODE (instrucao)
		case instrucao is
			when "0000" =>
				opcode1 <= disp0;
				opcode2 <= disp0;
				opcode3 <= disp0;
				opcode4 <= disp0;
			when "0001" =>
				opcode1 <= disp1;
				opcode2 <= disp0;
				opcode3 <= disp0;
				opcode4 <= disp0;
			when "0010" =>
				opcode1	<= disp0;
				opcode2	<= disp1;
				opcode3	<= disp0;
				opcode4	<= disp0;
			when "0011" =>
				opcode1	<= disp1;
				opcode2	<= disp1;
				opcode3	<= disp0;
				opcode4	<= disp0;
			when "0100" =>
				opcode1	<= disp0;
				opcode2	<= disp0;
				opcode3	<= disp1;
				opcode4	<= disp0;
			when "0101"=>
				opcode1	<= disp1;
				opcode2	<= disp0;
				opcode3	<= disp1;
				opcode4	<= disp0;
			when "0110"=>
				opcode1	<= disp0;
				opcode2	<= disp1;
				opcode3	<= disp1;
				opcode4	<= disp0;
			when "0111"=>
				--opcode1	<= disp1;
				--opcode2	<= disp1;
				--opcode3	<= disp1;
				--opcode4	<= disp0;
				opcode1 <= dispOff;
				opcode2 <= dispOff;
				opcode3 <= dispOff;
				opcode4 <= dispOff;
				
			when "1000"=>
				opcode1	<= disp0;
				opcode2	<= disp0;
				opcode3	<= disp0;
				opcode4	<= disp1;
			when "1001"=>
				--opcode1	<= disp1;
				--opcode2	<= disp0;
				--opcode3	<= disp0;
				--opcode4	<= disp1;
				opcode1 <= dispOff;
				opcode2 <= dispOff;
				opcode3 <= dispOff;
				opcode4 <= dispOff;
			when others =>
			
			end case;
			
		case cpu_out is
			when "0000" => -- cpu_out = 00
           
				rightDisp <= disp0;
			
				leftDisp <= disp0;
			
			when "0001" => -- cpu_out = 01
            
				rightDisp <= disp1;
			
				leftDisp <= disp0;
			
			when "0010" => -- cpu_out = 02 
			
				rightDisp <= disp2;
			
				leftDisp <= disp0;
         
			when "0011" => -- cpu_out = 03

				rightDisp <= disp3;
			  
				leftDisp <= disp0;
			  
			when "0100" => -- cpu_out = 04
			
				rightDisp <= disp4;

				leftDisp <= disp0;
			  
			when "0101" => -- cpu_out = 05

				rightDisp <= disp5;

				leftDisp <= disp0;
			
			when "0110" => -- cpu_out = 06

			  rightDisp <= disp6;

			  leftDisp <= disp0;
			  
			when "0111" => -- cpu_out = 07

				rightDisp <= disp7;

				leftDisp <= disp0;
			
			when "1000" => -- cpu_out = 08

				rightDisp <= disp8;
	
				leftDisp <= disp0;
			
			when "1001" => -- cpu_out = 09

				rightDisp <= disp9;
			
				leftDisp <= disp0;
			
			when "1010"=> -- cpu_out = 10

				rightDisp <= disp0;
			
				leftDisp <= disp1;
			
			when "1011"=> -- cpu_out = 11
			  
				rightDisp <= disp1;
			  
				leftDisp <= disp1;
			
			when "1100"=> -- cpu_out = 12

				rightDisp <= disp2;
			
				leftDisp <= disp1;
			
			when "1101"=> -- cpu_out = 13 
			  
				rightDisp <= disp3;
			  
				leftDisp <= disp1;
			  
			when "1110" => -- cpu_out = 14
			  
				rightDisp <= disp4;
			  
				leftDisp <= disp1;
			  
			when "1111"=> -- cpu_out = 15
			  
				rightDisp <= disp4;
			  
				leftDisp <= disp1;
			  
			end case;
		end if;
	end process;
end struc;