----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:53:42 07/25/2017 
-- Design Name: 
-- Module Name:    Exp_1 - Behavioral 
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

entity Exp_1 is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           c : in  STD_LOGIC;
           y : out  STD_LOGIC);
end Exp_1;

architecture Behavioral of Exp_1 is

signal a1,b1,c1,d1,d2,d3,o1:STD_LOGIC;


begin

a1<=not a;
b1<=not b;
c1<=not c;
d1<= a1 and c;
d2<= b1 and c;
d3<= a and b and c1;
o1<= d1 or d2 or d3;
y<= o1;


end Behavioral;

