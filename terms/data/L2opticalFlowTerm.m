%prox for G = alpha / 2 |u_t + \nabla u\cdot v|^2, where v is the unknown
classdef L2opticalFlowTerm < basicOpticalFlow & L2DataProxDual

    methods
        function obj = L2opticalFlowTerm(alpha,image1,image2,varargin)
            obj = obj@basicOpticalFlow(alpha,image1,image2,varargin);
            
            obj.CPPsupport = 1;
        end
    end
end