----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:33:14 08/29/2017 
-- Design Name: 
-- Module Name:    ALU_1 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ALU_1 is
    Port ( a : in  STD_LOGIC_VECTOR (3 downto 0);
           b : in  STD_LOGIC_VECTOR (3 downto 0);
           se : in  STD_LOGIC_VECTOR (1 downto 0);
           y : out  STD_LOGIC_VECTOR (3 downto 0));
end ALU_1;

architecture Behavioral of ALU_1 is
--import of mux
component mux4 is
	Port (  i : in  STD_LOGIC_VECTOR (3 downto 0);
           s : in  STD_LOGIC_VECTOR (1 downto 0);
			  e : in  STD_LOGIC;
           y : out  STD_LOGIC);
end component;
signal x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15:	STD_LOGIC;
begin
	x0<=  a(0) and b(0);
	x1<=  a(0) or b(0);
	x2<=  a(0) xor b(0);
	x3<=  not a(0);
	x4<=  a(1) and b(1);
	x5<=  a(1) or b(1);
	x6<=  a(1) xor b(1);
	x7<=  not a(1);
	x8<=  a(2) and b(2);
	x9<=  a(2) or b(2);
	x10<= a(2) xor b(2);
	x11<= not a(2);
	x12<= a(3) and b(3);
	x13<= a(3) or b(3);
	x14<= a(3) xor b(3);
	x15<= not a(3);
	
--define mux
	mux40 : mux4 port map(i(0)=>x0,i(1)=>x1,i(2)=>x2,i(3)=>x3,s(0)=>se(0),s(1)=>se(1),e=>'1',y=>y(0));
	mux41 : mux4 port map(i(0)=>x4,i(1)=>x5,i(2)=>x6,i(3)=>x7,s(0)=>se(0),s(1)=>se(1),e=>'1',y=>y(1));
	mux42 : mux4 port map(i(0)=>x8,i(1)=>x9,i(2)=>x10,i(3)=>x11,s(0)=>se(0),s(1)=>se(1),e=>'1',y=>y(2));
	mux43 : mux4 port map(i(0)=>x12,i(1)=>x13,i(2)=>x14,i(3)=>x15,s(0)=>se(0),s(1)=>se(1),e=>'1',y=>y(3));

end Behavioral;

