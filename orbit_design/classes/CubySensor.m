classdef CubySensor
    % A class for a sensor, that contains all important sensor properties
    % that are needed to compute GSD and swathwidth
    %   name:           Name of the Sensor
    %   focal_length:   Calibrated focal length of the sensor in m (!)
    %   pixel_pitch:    Center-to-center distance of CCD units in
    %                   m (!)
    %   s_prime:        length of CCD array
    %   numx:           number of CCD elements in across track direction
    %   pixel_depth:    number of bits used to hold a pixel
    %   line_rate:      number of line along track in 1s [Hz]
    %   spetral_band:   number of spectral bands

    
 
    properties
        name
        focal_length
        pixel_pitch
        s_prime
        numx
        pixel_depth
        line_rate
        spetral_band
        GSD
        swathwidth
        
    end
    
    methods
        function obj = CubySensor(name, focal_length, pixel_pitch, numx, pixel_depth, line_rate, spetral_band)
            % Construct an instance of this class
            %   
            obj.name = name;
            obj.focal_length = focal_length;
            obj.pixel_pitch = pixel_pitch;
            obj.pixel_depth = pixel_depth;
            obj.s_prime = pixel_pitch * numx;
            obj.numx = numx;
            obj.pixel_depth = pixel_depth;
            obj.line_rate = line_rate;
            obj.spetral_band = spetral_band;
            
        end
        
        function [swathwidth, GSD] = getSwathwidthGSD(obj,hg)
            % getSwathWidth Computes the swath width on ground for a given
            % orbital altitude above ground (assuming flat terrain and nadir-view)
            %   hg:     Height above ground in m (!)
            %   mb:     Photo scale figure assuming nadir view and flat terrain
            
            % Compute the swath width for the given altitude (output in
            % meter !)
            mb =  hg / obj.focal_length;
            swathwidth = mb * obj.s_prime;  % meter
            GSD = swathwidth / obj.numx;    % meter 
            fprintf('\n------------------------------------------------');
            fprintf("\nSensor name: \t\t\t%s\nHeight above ground:\t%f km \nSwath width: \t\t\t%f km \nGSD: \t\t\t\t\t%f m \n", obj.name, hg/1e3,swathwidth/1e3, GSD);
            fprintf('------------------------------------------------');
        end

        function [dl_bit] = DownlinkDataVolume(obj,obs_dur)
            % DownlinkDataVolume Computes the downlink data volume in bit for a
            % given observation duration in seconds
            
            %   obs_dur: observation duration [s]
            dl_bit =  obs_dur * obj.line_rate * obj.numx * obj.spetral_band * obj.pixel_depth;
        end

    end
end

