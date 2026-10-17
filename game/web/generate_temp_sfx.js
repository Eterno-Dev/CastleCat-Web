const fs = require('fs');
const path = require('path');

function generateWav(filename, frequency, durationMs, type='square') {
    const sampleRate = 44100;
    const numChannels = 1;
    const bitsPerSample = 16;
    const numSamples = Math.floor(sampleRate * durationMs / 1000);
    const blockAlign = numChannels * bitsPerSample / 8;
    const byteRate = sampleRate * blockAlign;
    const dataSize = numSamples * blockAlign;
    const chunkSize = 36 + dataSize;
    
    const buffer = Buffer.alloc(44 + dataSize);
    
    buffer.write('RIFF', 0);
    buffer.writeUInt32LE(chunkSize, 4);
    buffer.write('WAVE', 8);
    
    buffer.write('fmt ', 12);
    buffer.writeUInt32LE(16, 16);
    buffer.writeUInt16LE(1, 20);
    buffer.writeUInt16LE(numChannels, 22);
    buffer.writeUInt32LE(sampleRate, 24);
    buffer.writeUInt32LE(byteRate, 28);
    buffer.writeUInt16LE(blockAlign, 32);
    buffer.writeUInt16LE(bitsPerSample, 34);
    
    buffer.write('data', 36);
    buffer.writeUInt32LE(dataSize, 40);
    
    for (let i = 0; i < numSamples; i++) {
        const t = i / sampleRate;
        let value = 0;
        
        const envelope = 1 - (i / numSamples);
        
        if (type === 'square') {
            value = Math.sign(Math.sin(2 * Math.PI * frequency * t));
        } else if (type === 'noise') {
            value = Math.random() * 2 - 1;
        } else if (type === 'sine') {
            value = Math.sin(2 * Math.PI * frequency * t);
        }
        
        value = value * envelope * 0.15; // 15% volume
        
        const intValue = Math.max(-32768, Math.min(32767, Math.floor(value * 32767)));
        buffer.writeInt16LE(intValue, 44 + i * 2);
    }
    
    fs.writeFileSync(path.join(__dirname, filename), buffer);
    console.log(`Generated ${filename}`);
}

generateWav('sfx_hit_1.wav', 150, 150, 'noise');
generateWav('sfx_hit_2.wav', 200, 150, 'noise');
generateWav('sfx_hit_3.wav', 250, 150, 'noise');

generateWav('sfx_chest_1.wav', 600, 300, 'sine');
generateWav('sfx_chest_2.wav', 800, 300, 'sine');
generateWav('sfx_chest_3.wav', 1000, 400, 'sine');

generateWav('sfx_death.wav', 100, 800, 'square');

generateWav('sfx_atk_basic_1.wav', 400, 100, 'square');
generateWav('sfx_atk_basic_2.wav', 450, 100, 'square');
generateWav('sfx_atk_basic_3.wav', 500, 100, 'square');

generateWav('sfx_atk_str_1.wav', 300, 150, 'square');
generateWav('sfx_atk_str_2.wav', 250, 150, 'square');

generateWav('sfx_atk_agi_1.wav', 800, 80, 'sine');
generateWav('sfx_atk_agi_2.wav', 850, 80, 'sine');

generateWav('sfx_atk_mag_1.wav', 600, 200, 'sine');
generateWav('sfx_atk_mag_2.wav', 650, 200, 'sine');

console.log("All temporary SFX generated.");
