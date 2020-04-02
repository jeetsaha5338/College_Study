----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:05:54 07/25/2017 
-- Design Name: 
-- Module Name:    fulladder2 - Behavioral 
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

entity fulladder2 is
    Port ( a : in  STD_LOGIC_VECTOR (2 downto 0);
           s : out  STD_LOGIC;
           c : out  STD_LOGIC);
end fulladder2;

architecture Behavioral of fulladder2 is
component halfadder is
	 Port ( a : in  STD_LOGIC_VECTOR (1 downto 0);
           s : out  STD_LOGIC;
           c : out  STD_LOGIC);
end component;
signal s1,c1,c2: STD_LOGIC;
begin
halfadder0: halfadder port map(a(0)=>a(0),a(1)=>a(1),s=>s1,c=>c1);
halfadder1: halfadder port map(a(0)=>a(2),a(1)=>s1,s=>s,c=>c2);
c<=c1 or c2;
end Behavioral;

