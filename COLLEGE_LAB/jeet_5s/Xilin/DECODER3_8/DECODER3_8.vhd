----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:39:17 08/22/2017 
-- Design Name: 
-- Module Name:    DECODER3_8 - Behavioral 
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

entity DECODER3_8 is
    Port ( d : in  STD_LOGIC_VECTOR (2 downto 0);
           e : in  STD_LOGIC;
           y : out  STD_LOGIC_VECTOR (7 downto 0));
end DECODER3_8;

architecture Behavioral of DECODER3_8 is

begin
y(0)<= not d(2)and not d(1) and not d(0) and e;
y(1)<= not d(2)and not d(1) and d(0) and e;
y(2)<= not d(2)and d(1) and not d(0) and e;
y(3)<= not d(2)and d(1) and d(0) and e;
y(4)<= d(2) and not d(1) and not d(1) and not d(0)and e;
y(5)<= d(2) and not d(1) and d(0) and e;
y(6)<= d(2) and d(1) and not d(0) and e;
y(7)<= d(2) and d(1) and d(0) and e;			
 

end Behavioral;

