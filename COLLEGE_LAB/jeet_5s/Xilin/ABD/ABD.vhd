----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:41:55 07/18/2017 
-- Design Name: 
-- Module Name:    ABD - Behavioral 
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

entity ABD is
    Port ( a : in  STD_LOGIC_VECTOR (5 downto 0);
           y : out  STD_LOGIC);
end ABD;

architecture Behavioral of ABD is

begin

y <= a(0) and a(1) and a(2) and a(3) and a(4) and a(5) ;


end Behavioral;

