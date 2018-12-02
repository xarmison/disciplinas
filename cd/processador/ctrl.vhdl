-- controller unity
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity ctrl is
  port ( rst   : in STD_LOGIC;
         start : in STD_LOGIC;
         clk   : in STD_LOGIC;       
         imm   : out std_logic_vector(3 downto 0);
			modo_ALU : out std_logic_vector(2 downto 0);
			Reg_sel  : out std_logic_vector(1 downto 0);
			Reg_enable : out std_logic;
			acc_enb : out std_logic;
			codigoOP : out std_logic_vector(3 downto 0)
       );
end ctrl;

architecture fsm of ctrl is
  type state_type is (INICIO,SEARCH,INCREMENTPC,DECODE,ACC_EQ_REG,REG_EQ_ACC,LOADIMM,SOMA,SUBT,ANDOP,OROP,JUMP,INVERTE,GOBACK,done);
  signal state : state_type; 		
	
	constant mova	: std_logic_vector(3 downto 0) := "0000";
	constant movr  : std_logic_vector(3 downto 0) := "0001";
	constant load  : std_logic_vector(3 downto 0) := "0010";
	constant add	: std_logic_vector(3 downto 0) := "0011";
	constant sub	: std_logic_vector(3 downto 0) := "0100";
	constant andr  : std_logic_vector(3 downto 0) := "0101";
	constant orr   : std_logic_vector(3 downto 0) := "0110";
	constant jmp	: std_logic_vector(3 downto 0) := "0111";
	constant inv   : std_logic_vector(3 downto 0) := "1000";
	constant halt	: std_logic_vector(3 downto 0) := "1001";

	type PM_BLOCK is array (0 to 1) of std_logic_vector(7 downto 0);
	
	constant PM : PM_BLOCK := (
		--"00100001", --	load : acc = 1
		--"00010000", --	movr : r[00] = 1
		--"00100101", --	load : acc = 5
		--"00010100", --	movr : r[01] = 3
		--"00110000", --	add  : acc = 3 + 5
		"00100000",
		"10011111"	-- halt
	);

begin
	process (clk, rst, state) 
	variable IR			: std_logic_vector(7 downto 0);
	variable OPCODE 	: std_logic_vector(3 downto 0);
	variable ADDRESS 	: std_logic_vector(3 downto 0);
	variable REG_dd 	: std_logic_vector(1 downto 0); -- endereço registrador
	variable PC			: integer;
	
	begin
		if(clk'event and clk = '1') then		
		
      if(rst='1') then
			state<=INICIO;
		end if;
      --
      -- steady state
      --
      case state is
        
        when INICIO =>    -- steady state
          PC := 0;
          imm <= "0000";
			 acc_enb<='0';
			 reg_enable<='0';
          if (start = '1') then
            state <= SEARCH;
          else 
            state <= INICIO;
          end if;
          
        when SEARCH =>				-- fetch instruction
          IR := PM(PC);
          OPCODE := IR(7 downto 4);
			 codigoOP <= OPCODE;
          ADDRESS := IR(3 downto 0);
			 REG_dd := ADDRESS(3 downto 2);
          state <= INCREMENTPC;
          
        when INCREMENTPC =>				-- increment PC
          PC := PC + 1;
          state <= DECODE;
          
          
        when DECODE =>				-- decode instruction
          case OPCODE IS
            when mova => 
					state <= ACC_EQ_REG;
				
				when movr =>
					state <= REG_EQ_ACC;
				
				when load =>                       -- notice we can use
					state <= LOADIMM;					  -- the instruction
				  
				when add =>
					state	<= SOMA;
				
				when sub =>
					state <= SUBT;
				
				when andr =>
					state <= ANDOP;
				
				when orr =>
					state <= OROP;
				
				when jmp =>
					state <= JUMP;
				
				when inv	=>
					state <=	INVERTE;
				
            when halt =>                      -- and the machine code
					state <= done;						 -- interchangeably
              
            when others =>
              state <= SEARCH;
          end case;
			-- these states are the ones in which you actually
			-- start sending signals across
			-- to the datapath depending on what opcode is decoded.
			-- you add more states here.
			
        when ACC_EQ_REG =>
			Reg_sel		<=	REG_dd;
			Reg_enable	<=	'1';
			modo_ALU		<=	"000";
			acc_enb		<=	'1';
			state			<=	GOBACK;
		  
		  when REG_EQ_ACC =>
			Reg_sel	<= REG_dd;
			acc_enb	<= '0';
			modo_ALU	<= "001";
			state		<= GOBACK;
		  
        when LOADIMM =>                              -- load iiii
			imm 		<= address;                     -- set the immediate port
         modo_ALU	<= "010";
         acc_enb	<=	'1';                         -- to the lower_ir
         state 	<= GOBACK;
			 
        when SOMA =>
			Reg_sel		<= Reg_dd;
			Reg_enable	<= '1';
			modo_ALU		<= "011";
			acc_enb		<= '1';
			state			<= GOBACK;
		  
		  when SUBT =>
			Reg_sel		<= Reg_dd;
			Reg_enable	<= '1';
			modo_ALU		<= "100";
			acc_enb		<= '1';
			state			<= GOBACK;
		  
		  when ANDOP =>
			Reg_sel		<= Reg_dd;
			Reg_enable	<= '1';
			modo_ALU		<= "101";
			acc_enb		<= '1';
			state			<= GOBACK;
		  
		  when OROP =>
			Reg_sel		<= Reg_dd;
			Reg_enable	<= '1';
			modo_ALU		<= "110";
			acc_enb		<= '1';
			state			<= GOBACK;
		  
		  when JUMP =>
			PC	:= conv_integer(unsigned(ADDRESS));
			state <=	GOBACK;
		  
		  when INVERTE =>
			modo_ALU	<= "111";
			acc_enb	<= '1';
			state		<= GOBACK;
		  
        when GOBACK =>                              -- go back for next instruction
			Reg_enable	<= '0';
			acc_enb		<= '0';
			state 		<= SEARCH;
			
        when done =>                            -- stay here forever
          state <= done;
          
        when others =>
      end case;
    end if;
  end process;				
end fsm;