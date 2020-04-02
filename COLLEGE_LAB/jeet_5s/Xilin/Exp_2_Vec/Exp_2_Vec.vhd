----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:31:32 07/25/2017 
-- Design Name: 
-- Module Name:    Exp_2_Vec - Behavioral 
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

entity Exp_2_Vec is
    Port ( a : in  STD_LOGIC_VECTOR (3 downto 0);
           y : out  STD_LOGIC);
end Exp_2_Vec;

architecture Behavioral of Exp_2_Vec is

begin
y <= (not a(3) and a(1) and not a(0) ) or ( a(2) and not  a(1) and a(0) ) or  (a(3)and not a(2) and a(1) and a(0) );  

end Behavioral;

