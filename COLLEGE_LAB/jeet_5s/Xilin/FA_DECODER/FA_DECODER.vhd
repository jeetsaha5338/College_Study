----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:21:41 09/12/2017 
-- Design Name: 
-- Module Name:    FA_DECODER - Behavioral 
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

entity FA_DECODER is
    Port ( a : in  STD_LOGIC_VECTOR (2 downto 0);
           sum : out  STD_LOGIC;
           carry : out  STD_LOGIC);
end FA_DECODER;

architecture Behavioral of FA_DECODER is
component DECODER3_8 is 
		Port ( d : in  STD_LOGIC_VECTOR (2 downto 0);
           e : in  STD_LOGIC;
           y : out  STD_LOGIC_VECTOR (7 downto 0));
	end component;		  
signal b,c : STD_LOGIC_VECTOR (7 downto 0);
signal s1,s2,c1,c2:STD_LOGIC;
begin

dec0 :  DECODER3_8 port map (d(2)=>a(2),d(1)=>a(1),d(0)=>a(0),e=>'1',y(0)=>b(0),y(1)=>b(1),y(2)=>b(2),y(3)=>b(3),y(4)=>b(4),y(5)=>b(5),y(6)=>b(6),y(7)=>b(7));
			s1<=b(1)or b(2);
			s2<=b(4)or b(7);
			sum<=s1 or s2;	
dec1 :  DECODER3_8 port map (d(2)=>a(2),d(1)=>a(1),d(0)=>a(0),e=>'1',y(0)=>c(0),y(1)=>c(1),y(2)=>c(2),y(3)=>c(3),y(4)=>c(4),y(5)=>c(5),y(6)=>c(6),y(7)=>c(7));
			c1<=c(3) or c(5);
			c2<=c(6) or c(7);		
end Behavioral;

