----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:26:33 07/18/2017 
-- Design Name: 
-- Module Name:    PROJEXT2 - Behavioral 
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

entity PROJEXT2 is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           c : in  STD_LOGIC;
           y : out  STD_LOGIC);
end PROJEXT2;

architecture Behavioral of PROJEXT2 is
signal x1,x2,x3,x4,x5,x6,x7,y1,y2,y3,y4,y5,y6 : STD_LOGIC ;  
begin

x1 <= a and b;
x2 <= not c;
x3 <= b and c;
x4 <= not a;
x5 <= c and a;
x6 <= not b;
x7 <= a and b;
y1 <= x1 and x2;
y2 <= x3 and x4;
y3 <= x5 and x6;
y4 <= x7 and c;
y5 <= y1 or y2;
y6 <= y3 or y4;
y <= y5 or y6; 


end Behavioral;

