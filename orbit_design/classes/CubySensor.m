classdef CubySensor
    % A class for a sensor, that contains all important sensor properties
    % that are needed to compute GSD and swathwidth
    %   name:           Name of the Sensor
    %   focal_length:   Calibrated focal length of the sensor in m (!)
    %   pixel_pitch:    Center-to-center distance of CCD units in
    %                   m (!)
    %   s_prime:        length of CCD array
    %   numx:           number of CCD elements in across track direction

    
 
    properties
        name
        focal_length
        pixel_pitch
        s_prime
        numx
        
    end
    
    methods
        function obj = CubySensor(name, focal_length, pixel_pitch, numx)
            % Construct an instance of this class
            %   
            obj.name = name;
            obj.focal_length = focal_length;
            obj.pixel_pitch = pixel_pitch;
            obj.s_prime = pixel_pitch * numx;
            obj.numx = numx;
        end
        
        function [swathwidth, GSD] = getSwathwidth(obj,hg)
            % getSwathWidth Computes the swath width on ground for a given
            % orbital altitude above ground (assuming flat terrain and nadir-view)
            %   hg:     Height above ground in m (!)
            %   mb:     Photo scale figure assuming nadir view and flat terrain
            
            % Compute the swath width for the given altitude (output in
            % meter !)
            mb =  hg / obj.focal_length;
            swathwidth = mb * obj.s_prime;  % meter
            GSD = swathwidth / obj.numx;    % meter 
        end

    end
end

