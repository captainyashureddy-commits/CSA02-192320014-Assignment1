# Day 4 — Smart Meter Design Challenge

This C program accepts **96 fifteen-minute energy readings** (in watt-hours) for one day. It reports daily peak and off-peak consumption and estimates monthly energy by assuming the same day repeats for 30 days. The base monthly bill uses the assignment tariff: first 100 kWh free, next 100 kWh at Rs. 2.25/kWh, further energy at Rs. 4.50/kWh, plus Rs. 50 fixed charge. Monetary arithmetic uses integer paise and rounds only at the final tariff conversion.

The proposed time-of-day design classifies **18:00–22:00** as peak (intervals 73–88, using one-based numbering). A **25% peak premium** is a hypothetical policy option for discussion, **not** an assignment-specified or approved rate, and is **not** included in the displayed base bill. To implement an approved time-of-day bill, define tariff policy precisely (including slab interaction), then apply it consistently to interval data.

## Build and run

```bash
gcc -std=c11 -Wall -Wextra -o smart_meter smart_meter.c
./smart_meter
```

Enter 96 readings in Wh. For a simple test, enter `500` for each interval. Expected: daily energy 48.000 kWh, daily peak 8.000 kWh, daily off-peak 40.000 kWh, estimated monthly energy 1440.000 kWh, and base bill Rs. 5855.00 (100 free + 100 × 2.25 + 1240 × 4.50 + 50). Capture a real output screenshot and upload it to this folder.

## Storage and scalability

96 readings/day × 365 days = 35,040 readings per meter-year. At 4 bytes per reading, this is 140,160 bytes (~137 KiB) per household-year, before timestamps and metadata. For 4,000 households this is about 561 MB/year; for 800,000 households about 112.1 GB/year. Production systems should use timestamped interval records, validation, persistent storage, and explicit handling of missing or duplicate intervals.

## Limitations

This demonstration uses one representative day repeated over 30 days; it is not an actual month of 2,880 readings. A production billing system must ingest all readings and use approved time-of-day tariffs. It assumes readings represent energy per interval (Wh), not cumulative meter-register values.
