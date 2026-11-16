# MP3 (MPEG-1 Layer III) Decoder Test Vector Checklist

Version: 1.0

Purpose: Comprehensive verification of MPEG-1 Layer III (MP3) decoder compliance, robustness, and interoperability.

---

# 1. Bitstream Parsing

## 1.1 Frame Synchronization

### TV-BSP-001
**Description:** Valid sync word detection

**Input:**
- Well-formed MP3 stream

**Expected Result:**
- Decoder locates every frame correctly

---

### TV-BSP-002
**Description:** False sync rejection

**Input:**
- Random data containing accidental 0x7FF patterns

**Expected Result:**
- Decoder does not lock onto invalid frames

---

### TV-BSP-003
**Description:** Consecutive frame synchronization

**Expected Result:**
- No synchronization loss

---

### TV-BSP-004
**Description:** Resynchronization after corrupted frame

**Expected Result:**
- Decoder recovers on next valid frame

---

### TV-BSP-005
**Description:** Sync crossing byte boundaries

**Expected Result:**
- Correct frame detection

---

# 2. Header Validation

## MPEG Version

### TV-HDR-001
- MPEG-1 stream
- Expected: Accepted

### TV-HDR-002
- MPEG-2 stream
- Expected: Accepted if supported

### TV-HDR-003
- MPEG-2.5 stream
- Expected: Accepted if implemented extension

---

## Layer Validation

### TV-HDR-010
- Layer III
- Expected: Accepted

### TV-HDR-011
- Layer II
- Expected: Rejected by MP3-only decoder

### TV-HDR-012
- Layer I
- Expected: Rejected by MP3-only decoder

---

## Protection Bit

### TV-HDR-020
- CRC present

### TV-HDR-021
- CRC absent

---

## Bitrate Testing

### TV-HDR-030 through TV-HDR-044

Verify every legal MPEG-1 Layer III bitrate:

| Test ID | Bitrate |
|----------|----------|
| TV-HDR-030 | 32 kbps |
| TV-HDR-031 | 40 kbps |
| TV-HDR-032 | 48 kbps |
| TV-HDR-033 | 56 kbps |
| TV-HDR-034 | 64 kbps |
| TV-HDR-035 | 80 kbps |
| TV-HDR-036 | 96 kbps |
| TV-HDR-037 | 112 kbps |
| TV-HDR-038 | 128 kbps |
| TV-HDR-039 | 160 kbps |
| TV-HDR-040 | 192 kbps |
| TV-HDR-041 | 224 kbps |
| TV-HDR-042 | 256 kbps |
| TV-HDR-043 | 320 kbps |
| TV-HDR-044 | Free Format |

---

## Sample Rate Testing

### TV-HDR-050
- 32 kHz

### TV-HDR-051
- 44.1 kHz

### TV-HDR-052
- 48 kHz

---

## Padding

### TV-HDR-060
- Padding disabled

### TV-HDR-061
- Padding enabled

---

## Channel Modes

### TV-HDR-070
- Stereo

### TV-HDR-071
- Joint Stereo

### TV-HDR-072
- Dual Channel

### TV-HDR-073
- Mono

---

# 3. CRC Verification

### TV-CRC-001
Correct CRC

Expected:
- Successful decode

---

### TV-CRC-002
Corrupted CRC

Expected:
- Error detected

---

### TV-CRC-003
Single-bit error

Expected:
- CRC mismatch reported

---

### TV-CRC-004
Burst corruption

Expected:
- Decoder continues gracefully

---

# 4. Bit Reservoir

### TV-BR-001
No reservoir usage

---

### TV-BR-002
Small reservoir

---

### TV-BR-003
Medium reservoir

---

### TV-BR-004
Maximum reservoir usage

---

### TV-BR-005
Reservoir spanning 10+ frames

---

### TV-BR-006
main_data_begin = 0

---

### TV-BR-007
Maximum legal main_data_begin

---

### TV-BR-008
Reservoir underflow

Expected:
- Error detected

---

### TV-BR-009
Reservoir overflow

Expected:
- Stream rejected

---

# 5. Scalefactors

## Long Block

### TV-SCF-001
Minimum scalefactors

### TV-SCF-002
Maximum scalefactors

### TV-SCF-003
Uniform scalefactors

### TV-SCF-004
Random scalefactors

---

## Short Block

### TV-SCF-010
Unique scalefactors per window

### TV-SCF-011
Maximum values

### TV-SCF-012
Minimum values

---

## Mixed Block

### TV-SCF-020
Long region transition

### TV-SCF-021
Short region transition

---

# 6. Huffman Decoding

## Standard Tables

Generate vectors for every table.

### TV-HUF-001
Table 0

### TV-HUF-002
Table 1

...

### TV-HUF-032
Table 31

---

## Quad Tables

### TV-HUF-040
Count1 Table A

### TV-HUF-041
Count1 Table B

---

## Escape Coding

### TV-HUF-050
No escape

### TV-HUF-051
Single escape

### TV-HUF-052
Maximum escape

### TV-HUF-053
Consecutive escapes

---

## Codeword Stress

### TV-HUF-060
Shortest codeword

### TV-HUF-061
Longest codeword

### TV-HUF-062
Maximum coefficient magnitude

### TV-HUF-063
Region boundary crossing

---

# 7. Requantization

### TV-REQ-001
All coefficients zero

### TV-REQ-002
Small coefficients

### TV-REQ-003
Large coefficients

### TV-REQ-004
Maximum legal coefficient

### TV-REQ-005
Maximum global gain

### TV-REQ-006
Minimum global gain

---

# 8. Stereo Processing

## Independent Stereo

### TV-STR-001
Left channel only

### TV-STR-002
Right channel only

### TV-STR-003
Identical channels

### TV-STR-004
Independent channels

---

## Mid/Side Stereo

### TV-STR-010
Pure Mid/Side

### TV-STR-011
Partial Mid/Side

### TV-STR-012
Frame-by-frame switching

---

## Intensity Stereo

### TV-STR-020
Minimum position

### TV-STR-021
Maximum position

### TV-STR-022
Transition between positions

### TV-STR-023
Invalid position

---

# 9. Block Switching

### TV-BLK-001
Long block

### TV-BLK-002
Short block

### TV-BLK-003
Start block

### TV-BLK-004
Stop block

### TV-BLK-005
Rapid transitions

---

# 10. Alias Reduction

### TV-ALS-001
Long block alias reduction

### TV-ALS-002
Maximum alias values

### TV-ALS-003
Band boundary stress

### TV-ALS-004
Confirm omission for short blocks

---

# 11. IMDCT

## Long Block

### TV-IMD-001
Zero spectrum

### TV-IMD-002
Impulse coefficient

### TV-IMD-003
Single tone

### TV-IMD-004
Maximum energy

---

## Short Block

### TV-IMD-010
Window 1 active

### TV-IMD-011
Window 2 active

### TV-IMD-012
Window 3 active

---

## Overlap-Add

### TV-IMD-020
Perfect reconstruction

### TV-IMD-021
Transition smoothing

---

# 12. Hybrid Filterbank

### TV-HYB-001
Silence

### TV-HYB-002
One active subband

### TV-HYB-003
All active subbands

### TV-HYB-004
Impulse response

---

# 13. Polyphase Synthesis

### TV-POL-001
Impulse

### TV-POL-002
Step

### TV-POL-003
White noise

### TV-POL-004
Pink noise

### TV-POL-005
1 kHz sine

### TV-POL-006
Near Nyquist sine

### TV-POL-007
Multitone

---

# 14. Fault Injection

## Header Corruption

### TV-FLT-001
Invalid bitrate index

### TV-FLT-002
Invalid sample-rate index

### TV-FLT-003
Reserved layer

### TV-FLT-004
Reserved version

---

## Huffman Corruption

### TV-FLT-010
Single-bit error

### TV-FLT-011
Burst error

### TV-FLT-012
Corrupted region count

---

## Reservoir Corruption

### TV-FLT-020
Damaged previous frame

### TV-FLT-021
Truncated reservoir

---

## File Truncation

### TV-FLT-030
Truncated last frame

### TV-FLT-031
Truncated middle frame

---

# 15. Numerical Accuracy

### TV-ACC-001
Bit-exact comparison against reference decoder

### TV-ACC-002
Maximum PCM error measurement

### TV-ACC-003
RMS error measurement

### TV-ACC-004
Peak error measurement

Acceptance Criteria:

- Maximum PCM deviation <= 1 LSB
- No unexpected clipping
- No NaN or overflow conditions

---

# 16. Golden Reference Streams

## Mandatory Vectors

### TV-REF-001
Digital silence

### TV-REF-002
Single-sample impulse

### TV-REF-003
1 kHz sine

### TV-REF-004
Near-Nyquist sine

### TV-REF-005
White noise

### TV-REF-006
Pink noise

### TV-REF-007
Stereo phase inversion

### TV-REF-008
Pure Mid/Side encoded stream

### TV-REF-009
Intensity stereo stream

### TV-REF-010
Bit reservoir stress stream

### TV-REF-011
Free-format stream

### TV-REF-012
Deliberately corrupted stream

---

# Test Execution Summary

| Category | Total Cases |
|-----------|------------|
| Bitstream Parsing | 5 |
| Header Validation | 24 |
| CRC | 4 |
| Bit Reservoir | 9 |
| Scalefactors | 7 |
| Huffman | 37 |
| Requantization | 6 |
| Stereo Processing | 8 |
| Block Switching | 5 |
| Alias Reduction | 4 |
| IMDCT | 7 |
| Hybrid Filterbank | 4 |
| Polyphase Synthesis | 7 |
| Fault Injection | 11 |
| Accuracy | 4 |
| Reference Streams | 12 |

**Total Defined Test Cases:** 153