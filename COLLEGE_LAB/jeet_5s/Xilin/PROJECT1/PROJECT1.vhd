----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:11:51 07/18/2017 
-- Design Name: 
-- Module Name:    PROJECT1 - Behavioral 
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

entity PROJECT1 is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           c : in  STD_LOGIC;
           y : out  STD_LOGIC);
end PROJECT1;

architecture Behavioral of PROJECT1 is
signal x1,x2,x3,x4 : STD_LOGIC;
begin

	x1 <= a and b ;
	x2 <= b and c ;
	x3 <= c and a ;
	x4 <= x1 or x2 ;
	y <= x4 or x3 ;

end Behavioral;

