
#ifndef RLOOP_LCCM656__RLOOP__PI_COMMS_PI_COMMS__PACKET_TYPES_H_
#define RLOOP_LCCM656__RLOOP__PI_COMMS_PI_COMMS__PACKET_TYPES_H_


	/** Picomms standard packet types */
	typedef enum
	{

		/** unlock the pod STOP command
		 * U32 */
		PI_PACKET__PWRNODE__POD_STOP_UNLOCK_KEY = 0x5000U,

		/** Execute the pod STOP command
		 * U32 */
		PI_PACKET__PWRNODE__POD_STOP_COMMAND = 0x5001U,


		/** Brakes - Set the I-Beam distance
		 * F32, mm
		 */
		PI_PACKET__FCU_BRAKES__SET_IBEAM_DIST = 0x5100U,


		PI_PACKET__FCU_BRAKES__SET_LEFTMOTOR__MICROSTEPS = 0x5150U,
		PI_PACKET__FCU_BRAKES__SET_LEFTMOTOR__MAX_ACCEL = 0x5151U,
		PI_PACKET__FCU_BRAKES__SET_LEFTMOTOR__MICRO_REV = 0x5152U,
		PI_PACKET__FCU_BRAKES__SET_LEFTMOTOR__STEPS_REV = 0x5153U,
		PI_PACKET__FCU_BRAKES__SET_LEFTMOTOR__MAX_VELOC = 0x5154U,


		PI_PACKET__FCU_BRAKES__SET_RIGHTMOTOR__MICROSTEPS = 0x5160U,
		PI_PACKET__FCU_BRAKES__SET_RIGHTMOTOR__MAX_ACCEL = 0x5161U,
		PI_PACKET__FCU_BRAKES__SET_RIGHTMOTOR__MICRO_REV = 0x5162U,
		PI_PACKET__FCU_BRAKES__SET_RIGHTMOTOR__STEPS_REV = 0x5163U,
		PI_PACKET__FCU_BRAKES__SET_RIGHTMOTOR__MAX_VELOC = 0x5164U,


		PI_PACKET__FCU_BRAKES__LEFT__SCREW_POS = 0x5200U,
		PI_PACKET__FCU_BRAKES__RIGHT__SCREW_POS = 0x5201U,
		PI_PACKET__FCU_BRAKES__LEFT__LIMIT_EXTEND = 0x5202U,
		PI_PACKET__FCU_BRAKES__RIGHT__LIMIT_EXTEND = 0x5204U,
		PI_PACKET__FCU_BRAKES__LEFT__LIMIT_RETRACT = 0x5205U,
		PI_PACKET__FCU_BRAKES__RIGHT__LIMIT_RETRACT = 0x5206U,
		PI_PACKET__FCU_BRAKES__LEFT__IBEAM_DIST = 0x5207U,
		PI_PACKET__FCU_BRAKES__RIGHT__IBEAM_DIST = 0x5208U,
		PI_PACKET__FCU_BRAKES__LEFT__ADC_RAW = 0x5209U,
		PI_PACKET__FCU_BRAKES__RIGHT__ADC_RAW = 0x520AU,
		PI_PACKET__FCU_BRAKES__LEFT__MLP_SCALED = 0x520BU,
		PI_PACKET__FCU__BRAKES__RIGHT__MLP_SCALED = 0x520CU,


		PI_PACKET__FCU__LASER__PITCH_FL = 0x5300U,
		PI_PACKET__FCU__LASER__PITCH_FR = 0x5301U,
		PI_PACKET__FCU__LASER__PITCH_RL = 0x5302U,
		PI_PACKET__FCU__LASER__PITCH_RR = 0x5303U,
		PI_PACKET__FCU__LASER__YAW_F = 0x5304U,
		PI_PACKET__FCU__LASER__YAW_R = 0x5305U,


		PI_PACKET__FCU__PUSHER_SW_A = 0x5400U,
		PI_PACKET__FCU__PUSHER_SW_B = 0x5401U,
		PI_PACKET__FCU__PUSHER_STATE = 0x5402U,

		PI_PACKET__FCU__ACCEL1_X = 0x5500U,
		PI_PACKET__FCU__ACCEL1_Y = 0x5501U,
		PI_PACKET__FCU__ACCEL1_Z = 0x5502U,

		PI_PACKET__FCU__ACCEL1_GFORCE_X = 0x5503U,
		PI_PACKET__FCU__ACCEL1_GFORCE_Y = 0x5504U,
		PI_PACKET__FCU__ACCEL1_GFORCE_Z = 0x5505U,


		/** unlock the pod safe command
		 * U32 */
		PI_PACKET__PWRNODE__POD_SAFE_UNLOCK_KEY = 0xA000U,

		/** Execute the pod safe command
		 * U32 */
		PI_PACKET__PWRNODE__POD_SAFE_COMMAND = 0xA001U,


		/** Node temperature streaming control
		 * U8 */
		PI_PACKET__PWRNODE__NODE_TEMP_STREAM_CONTROL = 0xA100U,

		/** Node temperature data
		 * F32, Degrees C
		 */
		PI_PACKET__PWRNODE__NODE_TEMP_RETURN = 0xA101U,

		/** Node pressure streaming control
		 * U8 */
		PI_PACKET__PWRNODE__NODE_PRESS_STREAM_CONTROL = 0xA200U,

		/** Node pressure data
		 * F32, Bar
		 */
		PI_PACKET__PWRNODE__NODE_PRESS_RETURN = 0xA201U,


		/** Charge Relay Control
		 * U8 */
		PI_PACKET__PWRNODE__CHG_RELAY_CONTROL = 0xA300U,



	}E_PICOMMS__PACKET_TYPES_T;



#endif /* RLOOP_LCCM656__RLOOP__PI_COMMS_PI_COMMS__PACKET_TYPES_H_ */
