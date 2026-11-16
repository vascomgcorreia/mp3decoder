#define SYNC_WORD 0b111111111111
#define FRAME_BUFFER_SIZE 1152

typedef enum{

} bitrate;

typedef enum{

} fsampling;

typedef enum{
    MONO            = 0,
    STEREO          = 1,
    JOINT_STEREO    = 2
} chmode;

typedef struct{
    bitrate bit_rate;
    fsampling f_sampling;
    chmode ch_mode;
} frame_header;