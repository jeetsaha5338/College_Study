----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:06:29 09/12/2017 
-- Design Name: 
-- Module Name:    S_C_usingMUX - Behavioral 
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

entity S_C_usingMUX is
    Port ( a : in  STD_LOGIC_VECTOR (2 downto 0);
           carry : out  STD_LOGIC;
           sum : out  STD_LOGIC);
end S_C_usingMUX;

architecture Behavioral of S_C_usingMUX is

component mux4 is
    Port ( i : in  STD_LOGIC_VECTOR (3 downto 0);
           s : in  STD_LOGIC_VECTOR (1 downto 0);
			  e : in  STD_LOGIC;
           y : out  STD_LOGIC);
end component;

signal na: STD_LOGIC;

begin
na<=not a(2);
mux1 : mux4 port map (i(0)=>a(2),i(1)=>na,i(2)=>na,i(3)=>a(2),e=>'1',s(1)=>a(1),s(0)=>a(0),y=>sum);
mux2 : mux4 port map (i(0)=>'0',i(1)=>a(2),i(2)=>a(2),i(3)=>'1',s(1)=>a(1),s(0)=>a(0),y=>carry,e=>'1');

end Behavioral;

