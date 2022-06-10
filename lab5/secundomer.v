module secundomer(
input [1:0] KEY, // 0 - start,stop; 1 - reset
input CLOCK_50,

//регистр счётчика
output reg [18:0] pulse_counter,
output reg [3:0] pulse_counter_ms,
output reg [3:0] pulse_counter_s,
output reg [3:0] pulse_counter_10s,
output reg [3:0] pulse_counter_100s,

output reg [6:0] HEX0,
output reg [6:0] HEX1,
output reg [6:0] HEX2,
output reg [6:0] HEX3
);


//регистр нажатия клавы
reg device_running;

initial device_running <= 0;

//описание компаратора
wire hundredth_of_second_passed = (pulse_counter == 19'd499990); // debugging
wire decimals_of_second_passed = (pulse_counter_ms == 4'd9 && hundredth_of_second_passed);
wire second_passed = (pulse_counter_s == 4'd9 && decimals_of_second_passed);
wire ten_seconds_passed = (pulse_counter_10s == 4'd9 && second_passed);

//описание логики кнопик Пуск
always @(negedge KEY[0]) begin
	device_running <= ~device_running;
end

//описание счётчика сотых милисекунд
always @(posedge CLOCK_50 or posedge ~KEY[1]) begin
 if (~KEY[1]) pulse_counter <= 0; //асинхронный сброс
 else begin
	 if (device_running | hundredth_of_second_passed) begin
		 if (hundredth_of_second_passed) pulse_counter <= 0; //синхронный сброс
		 else pulse_counter <= pulse_counter + 19'd1;
	 end else pulse_counter <= pulse_counter; 
	end
end

//описание счётчика десятых милисекунд
always @(posedge CLOCK_50 or posedge ~KEY[1]) begin
 if (~KEY[1]) pulse_counter_ms <= 0; //асинхронный сброс
 else begin
	 if (hundredth_of_second_passed) begin
		 if (pulse_counter_ms == 4'd9) pulse_counter_ms <= 0; //синхронный сброс
		 else pulse_counter_ms <= pulse_counter_ms + 1;
	 end else pulse_counter_ms <= pulse_counter_ms; 
	end
end

//описание счётчика секунд
always @(posedge CLOCK_50 or posedge ~KEY[1]) begin
 if (~KEY[1]) pulse_counter_s <= 0; //асинхронный сброс
 else begin
	 if (decimals_of_second_passed) begin
		 if (pulse_counter_s == 4'd9) pulse_counter_s <= 0; //синхронный сброс
		 else pulse_counter_s <= pulse_counter_s + 1;
	 end else pulse_counter_s <= pulse_counter_s; 
	end
end

//описание счётчика десятых секунд
always @(posedge CLOCK_50 or posedge ~KEY[1]) begin
 if (~KEY[1]) pulse_counter_10s <= 0; //асинхронный сброс
 else begin
	 if (second_passed) begin
		 if (pulse_counter_10s == 4'd9) pulse_counter_10s <= 0; //синхронный сброс
		 else pulse_counter_10s <= pulse_counter_10s + 1;
	 end else pulse_counter_10s <= pulse_counter_10s; 
	end
end

always @(posedge CLOCK_50 or posedge ~KEY[1]) begin
 if (~KEY[1]) pulse_counter_100s <= 0; //асинхронный сброс
 else begin
	 if (ten_seconds_passed) begin
		 if (pulse_counter_100s == 4'd9) pulse_counter_100s <= 0; //синхронный сброс
		 else pulse_counter_100s <= pulse_counter_100s + 1;
	 end else pulse_counter_100s <= pulse_counter_100s; 
	end
end

always @(posedge CLOCK_50 or posedge ~KEY[1]) begin
	case(pulse_counter_ms)
		4'd0: HEX0 <= 7'b1000000;
		4'd1: HEX0 <= 7'b1111001;
		4'd2: HEX0 <= 7'b0100100;
		4'd3: HEX0 <= 7'b0110000;
		4'd4: HEX0 <= 7'b0011001;
		4'd5: HEX0 <= 7'b0010010;
		4'd6: HEX0 <= 7'b0000010;
		4'd7: HEX0 <= 7'b1111000;
		4'd8: HEX0 <= 7'b0000000;
		4'd9: HEX0 <= 7'b0010000;
		default: HEX0 <= 7'b1111111;
 endcase
	if (~KEY[1]) HEX0 <= 7'd1111111;
end

always @(posedge CLOCK_50 or posedge ~KEY[1]) begin
	case(pulse_counter_s)
		4'd0: HEX1 <= 7'b1000000;
		4'd1: HEX1 <= 7'b1111001;
		4'd2: HEX1 <= 7'b0100100;
		4'd3: HEX1 <= 7'b0110000;
		4'd4: HEX1 <= 7'b0011001;
		4'd5: HEX1 <= 7'b0010010;
		4'd6: HEX1 <= 7'b0000010;
		4'd7: HEX1 <= 7'b1111000;
		4'd8: HEX1 <= 7'b0000000;
		4'd9: HEX1 <= 7'b0010000;
		default: HEX1 <= 7'b1111111;
 endcase
	if (~KEY[1]) HEX1 <= 7'd1111111;
end

always @(posedge CLOCK_50 or posedge ~KEY[1]) begin
	case(pulse_counter_10s)
		4'd0: HEX2 <= 7'b1000000;
		4'd1: HEX2 <= 7'b1111001;
		4'd2: HEX2 <= 7'b0100100;
		4'd3: HEX2 <= 7'b0110000;
		4'd4: HEX2 <= 7'b0011001;
		4'd5: HEX2 <= 7'b0010010;
		4'd6: HEX2 <= 7'b0000010;
		4'd7: HEX2 <= 7'b1111000;
		4'd8: HEX2 <= 7'b0000000;
		4'd9: HEX2 <= 7'b0010000;
		default: HEX2 <= 7'b1111111;
 endcase
	if (~KEY[1]) HEX2 <= 7'd1111111;
end

always @(posedge CLOCK_50 or posedge ~KEY[1]) begin
	case(pulse_counter_100s)
		4'd0: HEX3 <= 7'b1000000;
		4'd1: HEX3 <= 7'b1111001;
		4'd2: HEX3 <= 7'b0100100;
		4'd3: HEX3 <= 7'b0110000;
		4'd4: HEX3 <= 7'b0011001;
		4'd5: HEX3 <= 7'b0010010;
		4'd6: HEX3 <= 7'b0000010;
		4'd7: HEX3 <= 7'b1111000;
		4'd8: HEX3 <= 7'b0000000;
		4'd9: HEX3 <= 7'b0010000;
		default: HEX3 <= 7'b1111111;
 endcase
	if (~KEY[1]) HEX3 <= 7'd1111111;
end

endmodule