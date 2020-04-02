----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:05:55 10/17/2017 
-- Design Name: 
-- Module Name:    LUT - Behavioral 
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

entity LUT is
    Port ( a : in  STD_LOGIC_VECTOR (2 downto 0);
           c : out  STD_LOGIC;
				sum: out STD_LOGIC	);
end LUT;

architecture Behavioral of LUT is

component mux2_1 is
	Port ( i : in  STD_LOGIC_VECTOR (1 downto 0);
           s : in  STD_LOGIC;
           y : out  STD_LOGIC);
end component;

signal p,q,x1,x2,x3,x4,x5,x6,k1,k2,k3,k4,k5,k6: STD_LOGIC;

begin
	p<='0';
	q<='1';
	
	MO: mux2_1 port map(i(0)=>p,i(1)=>p,s=>a(2),y=>x1);
	M1: mux2_1 port map(i(0)=>p,i(1)=>q,s=>a(2),y=>x2);
	M2: mux2_1 port map(i(0)=>p,i(1)=>q,s=>a(2),y=>x3);
	M3: mux2_1 port map(i(0)=>q,i(1)=>q,s=>a(2),y=>x4);
	M4: mux2_1 port map(i(0)=>x1,i(1)=>x2,s=>a(1),y=>x5);
	M5: mux2_1 port map(i(0)=>x3,i(1)=>x4,s=>a(1),y=>x6);
	M6: mux2_1 port map(i(0)=>x5,i(1)=>x6,s=>a(0),y=>c);
	
	M7: mux2_1 port map(i(0)=>p,i(1)=>q,s=>a(2),y=>k1);
	M8: mux2_1 port map(i(0)=>q,i(1)=>p,s=>a(2),y=>k2);
   M9: mux2_1 port map(i(0)=>q,i(1)=>p,s=>a(2),y=>k3);
	M10: mux2_1 port map(i(0)=>p,i(1)=>q,s=>a(2),y=>k4);
	M11: mux2_1 port map(i(0)=>k1,i(1)=>k2,s=>a(1),y=>k5);
	M12: mux2_1 port map(i(0)=>k3,i(1)=>k4,s=>a(1),y=>k6);
	M13: mux2_1 port map(i(0)=>k5,i(1)=>k6,s=>a(0),y=>sum);	
	

end Behavioral;

