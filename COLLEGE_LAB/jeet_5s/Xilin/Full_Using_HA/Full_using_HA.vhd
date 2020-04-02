----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:46:54 07/25/2017 
-- Design Name: 
-- Module Name:    Full_using_HA - Behavioral 
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

entity Full_using_HA is
    Port ( a : in  STD_LOGIC_VECTOR (2 downto 0);
           s : out  STD_LOGIC;
           c : out  STD_LOGIC);
end Full_using_HA;

						

architecture Behavioral of Full_using_HA is

component Half_Add is
			Port (
						a : in  STD_LOGIC;
						b : in  STD_LOGIC;
						s : out  STD_LOGIC;
						c : out  STD_LOGIC);
end component;

signal s1,s2,c1,c2: STD_LOGIC;


begin

	HA0: Half_Add Port map (a=>a(0),b=>a(1),s=>s1,c=>c1);
	HA1: Half_Add Port map (a=>a(2),b=>s1,s=>s,c=>c2);
	c<=c1 or c2;	

end Behavioral;

