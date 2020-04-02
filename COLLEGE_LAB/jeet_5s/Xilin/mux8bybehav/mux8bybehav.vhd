----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    23:37:47 08/21/2017 
-- Design Name: 
-- Module Name:    mux8bybehav - Behavioral 
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

entity mux8bybehav is
    Port ( i : in  STD_LOGIC_VECTOR (7 downto 0);
           s : in  STD_LOGIC_VECTOR (2 downto 0);
           e : in  STD_LOGIC;
           y : out  STD_LOGIC);
end mux8bybehav;

architecture Behavioral of mux8bybehav is

begin
	process(s,i)
	begin
		case s is
				when "000"=> y<=i(0);
				when "001"=> y<=i(1);
				when "010"=> y<=i(2);
				when "011"=> y<=i(3);
				when "100"=> y<=i(4);
				when "101"=> y<=i(5);
				when "110"=> y<=i(6);
				when "111"=> y<=i(7);
				when others=> y<=i(7);
		end case;
	end process;

end Behavioral;

