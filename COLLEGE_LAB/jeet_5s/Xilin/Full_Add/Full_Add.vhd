----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:10:42 07/25/2017 
-- Design Name: 
-- Module Name:    Full_Add - Behavioral 
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

entity Full_Add is
    Port ( a : in  STD_LOGIC_VECTOR (2 downto 0);
           s : out  STD_LOGIC;
           c  : out  STD_LOGIC);
end Full_Add;

architecture Behavioral of Full_Add is

begin

	s<= (a(2) xor a(1) ) xor a(0);
	c<= ( a(2) and a(1)) or ( a(1) and a(0)) or ( a(0) and a(2));

end Behavioral;
