----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:27:12 08/08/2017 
-- Design Name: 
-- Module Name:    Full_Add_Behavioural - Behavioral 
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

entity Full_Add_Behavioural is
    Port ( a : in  STD_LOGIC_VECTOR (2 downto 0);
           cout : out  STD_LOGIC;
           s : out  STD_LOGIC);
end Full_Add_Behavioural;

architecture Behavioral of Full_Add_Behavioural is

begin
	process(a)
		begin
		case a is
		 when "000" =>s<='0';cout<='0';
		 when "001" =>s<='1';cout<='0';
		 when "010" =>s<='1';cout<='0';
		 when "011" =>s<='0';cout<='1';
		 when "100" =>s<='1';cout<='0';
		 when "101" =>s<='0';cout<='1';
		 when "110" =>s<='0';cout<='1';
		 when others =>s<='1';cout<='1';
		 
		end case;
		end process;	

end Behavioral;

