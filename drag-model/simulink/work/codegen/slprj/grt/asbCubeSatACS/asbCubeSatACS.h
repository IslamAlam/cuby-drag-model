/*
 * Code generation for system model 'asbCubeSatACS'
 * For more details, see corresponding source file asbCubeSatACS.c
 *
 */

#ifndef RTW_HEADER_asbCubeSatACS_h_
#define RTW_HEADER_asbCubeSatACS_h_
#include <math.h>
#include <string.h>
#ifndef asbCubeSatACS_COMMON_INCLUDES_
# define asbCubeSatACS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* asbCubeSatACS_COMMON_INCLUDES_ */

#include "asbCubeSatACS_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Block signals for model 'asbCubeSatACS' */
typedef struct {
  StatesOutBus BusConversion_InsertedFor_Point;
  EnvBus BusConversion_InsertedFor_Poi_e;
  real_T ProportionalGain[3];          /* '<S206>/Proportional Gain' */
  real_T Integrator[3];                /* '<S201>/Integrator' */
  real_T DerivativeGain[3];            /* '<S195>/Derivative Gain' */
  real_T TSamp[3];                     /* '<S196>/TSamp' */
  real_T UD[3];                        /* '<S196>/UD' */
  real_T Diff[3];                      /* '<S196>/Diff' */
  real_T Sum[3];                       /* '<S210>/Sum' */
  real_T IntegralGain[3];              /* '<S198>/Integral Gain' */
  real_T ControlMode;                  /* '<S1>/Pointing Mode Selection' */
  real_T PointingCmd[3];               /* '<S1>/Pointing Mode Selection' */
  real_T Merge;                        /* '<S77>/Merge' */
  real_T Product;                      /* '<S157>/Product' */
  real_T Product1;                     /* '<S157>/Product1' */
  real_T Product2;                     /* '<S157>/Product2' */
  real_T Product3;                     /* '<S157>/Product3' */
  real_T Sum_n;                        /* '<S157>/Sum' */
  real_T sqrt_o;                       /* '<S156>/sqrt' */
  real_T Product2_f;                   /* '<S152>/Product2' */
  real_T Product6;                     /* '<S153>/Product6' */
  real_T Product3_b;                   /* '<S152>/Product3' */
  real_T Product7;                     /* '<S153>/Product7' */
  real_T Sum3;                         /* '<S153>/Sum3' */
  real_T Gain2;                        /* '<S153>/Gain2' */
  real_T Product8;                     /* '<S153>/Product8' */
  real_T Product1_d;                   /* '<S152>/Product1' */
  real_T Product_m;                    /* '<S153>/Product' */
  real_T Product_b;                    /* '<S152>/Product' */
  real_T Product1_l;                   /* '<S153>/Product1' */
  real_T Sum1;                         /* '<S153>/Sum1' */
  real_T Gain;                         /* '<S153>/Gain' */
  real_T Product4;                     /* '<S153>/Product4' */
  real_T Product2_e;                   /* '<S153>/Product2' */
  real_T Product3_i;                   /* '<S153>/Product3' */
  real_T Sum2;                         /* '<S153>/Sum2' */
  real_T Gain1;                        /* '<S153>/Gain1' */
  real_T Product5;                     /* '<S153>/Product5' */
  real_T Sum_p;                        /* '<S153>/Sum' */
  real_T Product_l;                    /* '<S154>/Product' */
  real_T Product1_g;                   /* '<S154>/Product1' */
  real_T Sum1_m;                       /* '<S154>/Sum1' */
  real_T Gain_a;                       /* '<S154>/Gain' */
  real_T Product4_k;                   /* '<S154>/Product4' */
  real_T Product6_o;                   /* '<S154>/Product6' */
  real_T Product7_d;                   /* '<S154>/Product7' */
  real_T Sum3_g;                       /* '<S154>/Sum3' */
  real_T Gain2_n;                      /* '<S154>/Gain2' */
  real_T Product8_a;                   /* '<S154>/Product8' */
  real_T Product2_a;                   /* '<S154>/Product2' */
  real_T Product3_h;                   /* '<S154>/Product3' */
  real_T Sum2_o;                       /* '<S154>/Sum2' */
  real_T Gain1_f;                      /* '<S154>/Gain1' */
  real_T Product5_p;                   /* '<S154>/Product5' */
  real_T Sum_o;                        /* '<S154>/Sum' */
  real_T Product_p;                    /* '<S155>/Product' */
  real_T Product1_dq;                  /* '<S155>/Product1' */
  real_T Sum1_j;                       /* '<S155>/Sum1' */
  real_T Gain_j;                       /* '<S155>/Gain' */
  real_T Product4_g;                   /* '<S155>/Product4' */
  real_T Product2_l;                   /* '<S155>/Product2' */
  real_T Product3_g;                   /* '<S155>/Product3' */
  real_T Sum2_m;                       /* '<S155>/Sum2' */
  real_T Gain1_o;                      /* '<S155>/Gain1' */
  real_T Product5_b;                   /* '<S155>/Product5' */
  real_T Product6_c;                   /* '<S155>/Product6' */
  real_T Product7_g;                   /* '<S155>/Product7' */
  real_T Sum3_c;                       /* '<S155>/Sum3' */
  real_T Gain2_a;                      /* '<S155>/Gain2' */
  real_T Product8_m;                   /* '<S155>/Product8' */
  real_T Sum_j;                        /* '<S155>/Sum' */
  real_T TmpSignalConversionAtDotProduct[3];
  real_T Product_bp;                   /* '<S163>/Product' */
  real_T Product1_f;                   /* '<S163>/Product1' */
  real_T Product2_j;                   /* '<S163>/Product2' */
  real_T Product3_d;                   /* '<S163>/Product3' */
  real_T Sum_h;                        /* '<S163>/Sum' */
  real_T sqrt_n;                       /* '<S162>/sqrt' */
  real_T Product2_c;                   /* '<S158>/Product2' */
  real_T Product6_b;                   /* '<S159>/Product6' */
  real_T Product3_e;                   /* '<S158>/Product3' */
  real_T Product7_b;                   /* '<S159>/Product7' */
  real_T Sum3_j;                       /* '<S159>/Sum3' */
  real_T Gain2_k;                      /* '<S159>/Gain2' */
  real_T Product8_o;                   /* '<S159>/Product8' */
  real_T Product1_a;                   /* '<S158>/Product1' */
  real_T Product_n;                    /* '<S159>/Product' */
  real_T Product_e;                    /* '<S158>/Product' */
  real_T Product1_k;                   /* '<S159>/Product1' */
  real_T Sum1_n;                       /* '<S159>/Sum1' */
  real_T Gain_m;                       /* '<S159>/Gain' */
  real_T Product4_p;                   /* '<S159>/Product4' */
  real_T Product2_h;                   /* '<S159>/Product2' */
  real_T Product3_m;                   /* '<S159>/Product3' */
  real_T Sum2_g;                       /* '<S159>/Sum2' */
  real_T Gain1_p;                      /* '<S159>/Gain1' */
  real_T Product5_f;                   /* '<S159>/Product5' */
  real_T Sum_oq;                       /* '<S159>/Sum' */
  real_T Product_g;                    /* '<S160>/Product' */
  real_T Product1_af;                  /* '<S160>/Product1' */
  real_T Sum1_h;                       /* '<S160>/Sum1' */
  real_T Gain_n;                       /* '<S160>/Gain' */
  real_T Product4_c;                   /* '<S160>/Product4' */
  real_T Product6_p;                   /* '<S160>/Product6' */
  real_T Product7_dp;                  /* '<S160>/Product7' */
  real_T Sum3_m;                       /* '<S160>/Sum3' */
  real_T Gain2_h;                      /* '<S160>/Gain2' */
  real_T Product8_p;                   /* '<S160>/Product8' */
  real_T Product2_k;                   /* '<S160>/Product2' */
  real_T Product3_c;                   /* '<S160>/Product3' */
  real_T Sum2_e;                       /* '<S160>/Sum2' */
  real_T Gain1_c;                      /* '<S160>/Gain1' */
  real_T Product5_i;                   /* '<S160>/Product5' */
  real_T Sum_i;                        /* '<S160>/Sum' */
  real_T Product_k;                    /* '<S161>/Product' */
  real_T Product1_m;                   /* '<S161>/Product1' */
  real_T Sum1_l;                       /* '<S161>/Sum1' */
  real_T Gain_k;                       /* '<S161>/Gain' */
  real_T Product4_i;                   /* '<S161>/Product4' */
  real_T Product2_m;                   /* '<S161>/Product2' */
  real_T Product3_p;                   /* '<S161>/Product3' */
  real_T Sum2_l;                       /* '<S161>/Sum2' */
  real_T Gain1_g;                      /* '<S161>/Gain1' */
  real_T Product5_d;                   /* '<S161>/Product5' */
  real_T Product6_i;                   /* '<S161>/Product6' */
  real_T Product7_bn;                  /* '<S161>/Product7' */
  real_T Sum3_g2;                      /* '<S161>/Sum3' */
  real_T Gain2_m;                      /* '<S161>/Gain2' */
  real_T Product8_me;                  /* '<S161>/Product8' */
  real_T Sum_d;                        /* '<S161>/Sum' */
  real_T TmpSignalConversionAtDotProdu_k[3];
  real_T DotProduct3;                  /* '<S78>/Dot Product3' */
  real_T DotProduct1;                  /* '<S78>/Dot Product1' */
  real_T DotProduct2;                  /* '<S78>/Dot Product2' */
  real_T Divide1;                      /* '<S78>/Divide1' */
  real_T Sqrt3;                        /* '<S78>/Sqrt3' */
  real_T Divide;                       /* '<S78>/Divide' */
  real_T Bias;                         /* '<S78>/Bias' */
  real_T Abs;                          /* '<S78>/Abs' */
  real_T Bias1;                        /* '<S78>/Bias1' */
  real_T Abs1;                         /* '<S78>/Abs1' */
  real_T Merge_d;                      /* '<S78>/Merge' */
  real_T DotProduct3_g;                /* '<S84>/Dot Product3' */
  real_T DotProduct2_j;                /* '<S84>/Dot Product2' */
  real_T Divide1_e;                    /* '<S84>/Divide1' */
  real_T Sqrt3_n;                      /* '<S84>/Sqrt3' */
  real_T Add2;                         /* '<S84>/Add2' */
  real_T Product_e5;                   /* '<S124>/Product' */
  real_T DotProduct3_f;                /* '<S111>/Dot Product3' */
  real_T DotProduct2_f;                /* '<S111>/Dot Product2' */
  real_T Divide1_n;                    /* '<S111>/Divide1' */
  real_T Sqrt3_j;                      /* '<S111>/Sqrt3' */
  real_T Divide_d;                     /* '<S111>/Divide' */
  real_T Bias_i;                       /* '<S111>/Bias' */
  real_T Abs_l;                        /* '<S111>/Abs' */
  real_T Bias1_n;                      /* '<S111>/Bias1' */
  real_T Abs1_n;                       /* '<S111>/Abs1' */
  real_T Merge_m;                      /* '<S111>/Merge' */
  real_T is180degRot[3];               /* '<S84>/is 180deg Rot' */
  real_T Product1_df;                  /* '<S124>/Product1' */
  real_T Product2_mt;                  /* '<S124>/Product2' */
  real_T Product3_n;                   /* '<S124>/Product3' */
  real_T Sum_c;                        /* '<S124>/Sum' */
  real_T sqrt_j;                       /* '<S123>/sqrt' */
  real_T Product_c;                    /* '<S114>/Product' */
  real_T Product2_mn;                  /* '<S114>/Product2' */
  real_T Product_po;                   /* '<S103>/Product' */
  real_T Product1_gf;                  /* '<S114>/Product1' */
  real_T Product1_h;                   /* '<S103>/Product1' */
  real_T Product2_o;                   /* '<S103>/Product2' */
  real_T Product3_j;                   /* '<S114>/Product3' */
  real_T Product3_o;                   /* '<S103>/Product3' */
  real_T Sum_pg;                       /* '<S103>/Sum' */
  real_T sqrt_om;                      /* '<S102>/sqrt' */
  real_T Product2_i;                   /* '<S98>/Product2' */
  real_T Product6_f;                   /* '<S99>/Product6' */
  real_T Product3_k;                   /* '<S98>/Product3' */
  real_T Product7_f;                   /* '<S99>/Product7' */
  real_T Sum3_mb;                      /* '<S99>/Sum3' */
  real_T Gain2_d;                      /* '<S99>/Gain2' */
  real_T Product8_d;                   /* '<S99>/Product8' */
  real_T Product1_l2;                  /* '<S98>/Product1' */
  real_T Product_ks;                   /* '<S99>/Product' */
  real_T Product_mm;                   /* '<S98>/Product' */
  real_T Product1_b;                   /* '<S99>/Product1' */
  real_T Sum1_k;                       /* '<S99>/Sum1' */
  real_T Gain_g;                       /* '<S99>/Gain' */
  real_T Product4_n;                   /* '<S99>/Product4' */
  real_T Product2_hp;                  /* '<S99>/Product2' */
  real_T Product3_a;                   /* '<S99>/Product3' */
  real_T Sum2_lr;                      /* '<S99>/Sum2' */
  real_T Gain1_m;                      /* '<S99>/Gain1' */
  real_T Product5_c;                   /* '<S99>/Product5' */
  real_T Sum_pp;                       /* '<S99>/Sum' */
  real_T Product_h;                    /* '<S100>/Product' */
  real_T Product1_p;                   /* '<S100>/Product1' */
  real_T Sum1_hn;                      /* '<S100>/Sum1' */
  real_T Gain_b;                       /* '<S100>/Gain' */
  real_T Product4_j;                   /* '<S100>/Product4' */
  real_T Product6_d;                   /* '<S100>/Product6' */
  real_T Product7_l;                   /* '<S100>/Product7' */
  real_T Sum3_k;                       /* '<S100>/Sum3' */
  real_T Gain2_f;                      /* '<S100>/Gain2' */
  real_T Product8_h;                   /* '<S100>/Product8' */
  real_T Product2_p;                   /* '<S100>/Product2' */
  real_T Product3_o3;                  /* '<S100>/Product3' */
  real_T Sum2_d;                       /* '<S100>/Sum2' */
  real_T Gain1_l;                      /* '<S100>/Gain1' */
  real_T Product5_j;                   /* '<S100>/Product5' */
  real_T Sum_e;                        /* '<S100>/Sum' */
  real_T Product_j;                    /* '<S101>/Product' */
  real_T Product1_ly;                  /* '<S101>/Product1' */
  real_T Sum1_k2;                      /* '<S101>/Sum1' */
  real_T Gain_o;                       /* '<S101>/Gain' */
  real_T Product4_l;                   /* '<S101>/Product4' */
  real_T Product2_a1;                  /* '<S101>/Product2' */
  real_T Product3_j0;                  /* '<S101>/Product3' */
  real_T Sum2_gz;                      /* '<S101>/Sum2' */
  real_T Gain1_d;                      /* '<S101>/Gain1' */
  real_T Product5_pr;                  /* '<S101>/Product5' */
  real_T Product6_k;                   /* '<S101>/Product6' */
  real_T Product7_e;                   /* '<S101>/Product7' */
  real_T Sum3_o;                       /* '<S101>/Sum3' */
  real_T Gain2_p;                      /* '<S101>/Gain2' */
  real_T Product8_f;                   /* '<S101>/Product8' */
  real_T Sum_di;                       /* '<S101>/Sum' */
  real_T TmpSignalConversionAtDotProdu_p[3];
  real_T jxk;                          /* '<S148>/j x k' */
  real_T kxi;                          /* '<S148>/k x i' */
  real_T ixj;                          /* '<S148>/i x j' */
  real_T kxj;                          /* '<S149>/k x j' */
  real_T ixk;                          /* '<S149>/i x k' */
  real_T jxi;                          /* '<S149>/j x i' */
  real_T Sum_f[3];                     /* '<S146>/Sum' */
  real_T jxk_g;                        /* '<S150>/j x k' */
  real_T kxi_f;                        /* '<S150>/k x i' */
  real_T ixj_j;                        /* '<S150>/i x j' */
  real_T kxj_j;                        /* '<S151>/k x j' */
  real_T ixk_p;                        /* '<S151>/i x k' */
  real_T jxi_d;                        /* '<S151>/j x i' */
  real_T Sum_a[3];                     /* '<S147>/Sum' */
  real_T Product_lv;                   /* '<S109>/Product' */
  real_T Product1_fw;                  /* '<S109>/Product1' */
  real_T Product2_ie;                  /* '<S109>/Product2' */
  real_T Product3_c5;                  /* '<S109>/Product3' */
  real_T Sum_hq;                       /* '<S109>/Sum' */
  real_T sqrt_d;                       /* '<S108>/sqrt' */
  real_T Product2_b;                   /* '<S104>/Product2' */
  real_T Product6_h;                   /* '<S105>/Product6' */
  real_T Product3_nk;                  /* '<S104>/Product3' */
  real_T Product7_p;                   /* '<S105>/Product7' */
  real_T Sum3_h;                       /* '<S105>/Sum3' */
  real_T Gain2_j;                      /* '<S105>/Gain2' */
  real_T Product8_b;                   /* '<S105>/Product8' */
  real_T Product1_e;                   /* '<S104>/Product1' */
  real_T Product_a;                    /* '<S105>/Product' */
  real_T Product_ji;                   /* '<S104>/Product' */
  real_T Product1_j;                   /* '<S105>/Product1' */
  real_T Sum1_mh;                      /* '<S105>/Sum1' */
  real_T Gain_ms;                      /* '<S105>/Gain' */
  real_T Product4_b;                   /* '<S105>/Product4' */
  real_T Product2_ll;                  /* '<S105>/Product2' */
  real_T Product3_ek;                  /* '<S105>/Product3' */
  real_T Sum2_f;                       /* '<S105>/Sum2' */
  real_T Gain1_lz;                     /* '<S105>/Gain1' */
  real_T Product5_fk;                  /* '<S105>/Product5' */
  real_T Sum_eb;                       /* '<S105>/Sum' */
  real_T Product_o;                    /* '<S106>/Product' */
  real_T Product1_pi;                  /* '<S106>/Product1' */
  real_T Sum1_g;                       /* '<S106>/Sum1' */
  real_T Gain_jv;                      /* '<S106>/Gain' */
  real_T Product4_e;                   /* '<S106>/Product4' */
  real_T Product6_fq;                  /* '<S106>/Product6' */
  real_T Product7_c;                   /* '<S106>/Product7' */
  real_T Sum3_n;                       /* '<S106>/Sum3' */
  real_T Gain2_o;                      /* '<S106>/Gain2' */
  real_T Product8_bs;                  /* '<S106>/Product8' */
  real_T Product2_g;                   /* '<S106>/Product2' */
  real_T Product3_jj;                  /* '<S106>/Product3' */
  real_T Sum2_dw;                      /* '<S106>/Sum2' */
  real_T Gain1_fu;                     /* '<S106>/Gain1' */
  real_T Product5_g;                   /* '<S106>/Product5' */
  real_T Sum_oc;                       /* '<S106>/Sum' */
  real_T Product_ex;                   /* '<S107>/Product' */
  real_T Product1_i;                   /* '<S107>/Product1' */
  real_T Sum1_f;                       /* '<S107>/Sum1' */
  real_T Gain_gb;                      /* '<S107>/Gain' */
  real_T Product4_d;                   /* '<S107>/Product4' */
  real_T Product2_gk;                  /* '<S107>/Product2' */
  real_T Product3_nl;                  /* '<S107>/Product3' */
  real_T Sum2_fp;                      /* '<S107>/Sum2' */
  real_T Gain1_k;                      /* '<S107>/Gain1' */
  real_T Product5_e;                   /* '<S107>/Product5' */
  real_T Product6_br;                  /* '<S107>/Product6' */
  real_T Product7_d2;                  /* '<S107>/Product7' */
  real_T Sum3_f;                       /* '<S107>/Sum3' */
  real_T Gain2_h1;                     /* '<S107>/Gain2' */
  real_T Product8_c;                   /* '<S107>/Product8' */
  real_T Sum_jt;                       /* '<S107>/Sum' */
  real_T TmpSignalConversionAtDotProdu_f[3];
  real_T DotProduct3_n;                /* '<S126>/Dot Product3' */
  real_T DotProduct1_n;                /* '<S126>/Dot Product1' */
  real_T DotProduct2_k;                /* '<S126>/Dot Product2' */
  real_T Divide1_l;                    /* '<S126>/Divide1' */
  real_T Sqrt3_j1;                     /* '<S126>/Sqrt3' */
  real_T Divide_l;                     /* '<S126>/Divide' */
  real_T Bias_h;                       /* '<S126>/Bias' */
  real_T Abs_c;                        /* '<S126>/Abs' */
  real_T Bias1_d;                      /* '<S126>/Bias1' */
  real_T Abs1_e;                       /* '<S126>/Abs1' */
  real_T Merge_c;                      /* '<S126>/Merge' */
  real_T Switch[4];                    /* '<S73>/Switch' */
  real_T Product_d;                    /* '<S171>/Product' */
  real_T Product1_h4;                  /* '<S171>/Product1' */
  real_T Product2_po;                  /* '<S171>/Product2' */
  real_T Product3_pz;                  /* '<S171>/Product3' */
  real_T Sum_aq;                       /* '<S171>/Sum' */
  real_T sqrt_k;                       /* '<S170>/sqrt' */
  real_T Product_mw;                   /* '<S165>/Product' */
  real_T Product1_lc;                  /* '<S165>/Product1' */
  real_T Product2_el;                  /* '<S165>/Product2' */
  real_T Product3_e1;                  /* '<S165>/Product3' */
  real_T fcn3;                         /* '<S76>/fcn3' */
  real_T Merge_j;                      /* '<S166>/Merge' */
  real_T fcn1;                         /* '<S76>/fcn1' */
  real_T fcn2;                         /* '<S76>/fcn2' */
  real_T fcn4;                         /* '<S76>/fcn4' */
  real_T fcn5;                         /* '<S76>/fcn5' */
  real_T jxi_g;                        /* '<S116>/j x i' */
  real_T ixk_f;                        /* '<S116>/i x k' */
  real_T kxj_d;                        /* '<S116>/k x j' */
  real_T ixj_k;                        /* '<S115>/i x j' */
  real_T kxi_d;                        /* '<S115>/k x i' */
  real_T jxk_d;                        /* '<S115>/j x k' */
  real_T Sum_jb[3];                    /* '<S110>/Sum' */
  real_T is180degRot_c[3];             /* '<S85>/is 180deg Rot' */
  real_T Product3_mu;                  /* '<S139>/Product3' */
  real_T Product2_d;                   /* '<S139>/Product2' */
  real_T Product1_fq;                  /* '<S139>/Product1' */
  real_T DotProduct2_b;                /* '<S85>/Dot Product2' */
  real_T DotProduct1_b;                /* '<S85>/Dot Product1' */
  real_T Divide1_m;                    /* '<S85>/Divide1' */
  real_T Sqrt3_b;                      /* '<S85>/Sqrt3' */
  real_T DotProduct3_i;                /* '<S85>/Dot Product3' */
  real_T Add2_a;                       /* '<S85>/Add2' */
  real_T Product_mk;                   /* '<S139>/Product' */
  real_T Sum_b;                        /* '<S139>/Sum' */
  real_T sqrt_c;                       /* '<S138>/sqrt' */
  real_T Product3_mk;                  /* '<S129>/Product3' */
  real_T Product3_i2;                  /* '<S94>/Product3' */
  real_T Product2_jr;                  /* '<S129>/Product2' */
  real_T Product2_lv;                  /* '<S94>/Product2' */
  real_T Product1_hl;                  /* '<S129>/Product1' */
  real_T Product1_bp;                  /* '<S94>/Product1' */
  real_T Product_kg;                   /* '<S129>/Product' */
  real_T Product_bpv;                  /* '<S94>/Product' */
  real_T Sum_m;                        /* '<S94>/Sum' */
  real_T Product3_ee;                  /* '<S95>/Product3' */
  real_T Product2_o2;                  /* '<S95>/Product2' */
  real_T Product1_ju;                  /* '<S95>/Product1' */
  real_T Product_f;                    /* '<S95>/Product' */
  real_T Sum_ei;                       /* '<S95>/Sum' */
  real_T Product3_l;                   /* '<S96>/Product3' */
  real_T Product2_oq;                  /* '<S96>/Product2' */
  real_T Product1_f1;                  /* '<S96>/Product1' */
  real_T Product_gh;                   /* '<S96>/Product' */
  real_T Sum_l;                        /* '<S96>/Sum' */
  real_T Product3_mo;                  /* '<S97>/Product3' */
  real_T Product2_kz;                  /* '<S97>/Product2' */
  real_T Product1_mz;                  /* '<S97>/Product1' */
  real_T Product_eo;                   /* '<S97>/Product' */
  real_T Sum_nv;                       /* '<S97>/Sum' */
  real_T jxi_o;                        /* '<S131>/j x i' */
  real_T ixk_l;                        /* '<S131>/i x k' */
  real_T kxj_b;                        /* '<S131>/k x j' */
  real_T ixj_f;                        /* '<S130>/i x j' */
  real_T kxi_o;                        /* '<S130>/k x i' */
  real_T jxk_h;                        /* '<S130>/j x k' */
  real_T Sum_le[3];                    /* '<S125>/Sum' */
  real_T Switch3[3];                   /* '<S128>/Switch3' */
  real_T jxi_c;                        /* '<S137>/j x i' */
  real_T ixk_m;                        /* '<S137>/i x k' */
  real_T kxj_c;                        /* '<S137>/k x j' */
  real_T ixj_m;                        /* '<S136>/i x j' */
  real_T kxi_dm;                       /* '<S136>/k x i' */
  real_T jxk_m;                        /* '<S136>/j x k' */
  real_T Sum_g[3];                     /* '<S135>/Sum' */
  real_T Gain_b2;                      /* '<S128>/Gain' */
  real_T Gain2_od;                     /* '<S128>/Gain2' */
  real_T jxk_n;                        /* '<S19>/j x k' */
  real_T kxi_p;                        /* '<S19>/k x i' */
  real_T ixj_k3;                       /* '<S19>/i x j' */
  real_T kxj_n;                        /* '<S20>/k x j' */
  real_T ixk_k;                        /* '<S20>/i x k' */
  real_T jxi_b;                        /* '<S20>/j x i' */
  real_T Sum_ou[3];                    /* '<S12>/Sum' */
  real_T zr[3];                        /* '<S7>/z = -r' */
  real_T ixj_i;                        /* '<S17>/i x j' */
  real_T jxk_i;                        /* '<S17>/j x k' */
  real_T kxi_os;                       /* '<S17>/k x i' */
  real_T ixk_g;                        /* '<S18>/i x k' */
  real_T jxi_ok;                       /* '<S18>/j x i' */
  real_T kxj_g;                        /* '<S18>/k x j' */
  real_T Sum_dv[3];                    /* '<S11>/Sum' */
  real_T DotProduct;                   /* '<S14>/Dot Product' */
  real_T SumofElements;                /* '<S14>/Sum of Elements' */
  real_T MathFunction1;                /* '<S14>/Math Function1' */
  real_T DotProduct_m;                 /* '<S15>/Dot Product' */
  real_T SumofElements_h;              /* '<S15>/Sum of Elements' */
  real_T MathFunction1_n;              /* '<S15>/Math Function1' */
  real_T DotProduct_b;                 /* '<S16>/Dot Product' */
  real_T SumofElements_g;              /* '<S16>/Sum of Elements' */
  real_T MathFunction1_ni;             /* '<S16>/Math Function1' */
  real_T ORFtoECEF[9];                 /* '<S7>/ORF to ECEF' */
  real_T ECEFtoORF[9];                 /* '<S7>/ECEF to ORF' */
  real_T Add;                          /* '<S24>/Add' */
  real_T Merge_e[4];                   /* '<S13>/Merge' */
  real_T Product_ky;                   /* '<S60>/Product' */
  real_T Product1_li;                  /* '<S60>/Product1' */
  real_T Product2_gb;                  /* '<S60>/Product2' */
  real_T Product3_an;                  /* '<S60>/Product3' */
  real_T Sum_hk;                       /* '<S60>/Sum' */
  real_T Divide_j;                     /* '<S8>/Divide' */
  real_T UnaryMinus;                   /* '<S59>/Unary Minus' */
  real_T Divide1_d;                    /* '<S8>/Divide1' */
  real_T UnaryMinus1;                  /* '<S59>/Unary Minus1' */
  real_T Divide2;                      /* '<S8>/Divide2' */
  real_T UnaryMinus2;                  /* '<S59>/Unary Minus2' */
  real_T Divide3;                      /* '<S8>/Divide3' */
  real_T Product_pb;                   /* '<S61>/Product' */
  real_T Product1_pg;                  /* '<S61>/Product1' */
  real_T Product2_mw;                  /* '<S61>/Product2' */
  real_T Product3_cd;                  /* '<S61>/Product3' */
  real_T Sum_fj;                       /* '<S61>/Sum' */
  real_T Product_la;                   /* '<S62>/Product' */
  real_T Product1_p5;                  /* '<S62>/Product1' */
  real_T Product2_jd;                  /* '<S62>/Product2' */
  real_T Product3_db;                  /* '<S62>/Product3' */
  real_T Sum_c3;                       /* '<S62>/Sum' */
  real_T Product_nm;                   /* '<S63>/Product' */
  real_T Product1_o;                   /* '<S63>/Product1' */
  real_T Product2_bn;                  /* '<S63>/Product2' */
  real_T Product3_gc;                  /* '<S63>/Product3' */
  real_T Sum_hn;                       /* '<S63>/Sum' */
  real_T Product_m0;                   /* '<S64>/Product' */
  real_T Product1_eo;                  /* '<S64>/Product1' */
  real_T Product2_dz;                  /* '<S64>/Product2' */
  real_T Product3_ox;                  /* '<S64>/Product3' */
  real_T Sum_h4;                       /* '<S64>/Sum' */
  real_T Product_mx;                   /* '<S72>/Product' */
  real_T Product1_fz;                  /* '<S72>/Product1' */
  real_T Product2_p4;                  /* '<S72>/Product2' */
  real_T Product3_kb;                  /* '<S72>/Product3' */
  real_T Sum_k;                        /* '<S72>/Sum' */
  real_T sqrt_jz;                      /* '<S71>/sqrt' */
  real_T Product_j5;                   /* '<S66>/Product' */
  real_T Product1_ik;                  /* '<S66>/Product1' */
  real_T Product2_ev;                  /* '<S66>/Product2' */
  real_T Product3_f;                   /* '<S66>/Product3' */
  real_T fcn3_l;                       /* '<S10>/fcn3' */
  real_T Merge_cv;                     /* '<S67>/Merge' */
  real_T fcn1_l;                       /* '<S10>/fcn1' */
  real_T fcn2_k;                       /* '<S10>/fcn2' */
  real_T fcn4_e;                       /* '<S10>/fcn4' */
  real_T fcn5_p;                       /* '<S10>/fcn5' */
  real_T Product_f0;                   /* '<S57>/Product' */
  real_T Product1_ey;                  /* '<S57>/Product1' */
  real_T Product2_os;                  /* '<S57>/Product2' */
  real_T Product3_bo;                  /* '<S57>/Product3' */
  real_T Product4_i1;                  /* '<S57>/Product4' */
  real_T Product5_pt;                  /* '<S57>/Product5' */
  real_T detMatrix;                    /* '<S57>/Sum' */
  real_T Bias_c;                       /* '<S51>/Bias' */
  real_T Abs1_o;                       /* '<S51>/Abs1' */
  real_T MathFunction[9];              /* '<S50>/Math Function' */
  real_T Product_mn[9];                /* '<S50>/Product' */
  real_T Bias1_e[9];                   /* '<S50>/Bias1' */
  real_T Abs2[9];                      /* '<S50>/Abs2' */
  real_T Add_d;                        /* '<S33>/Add' */
  real_T sqrt_nk;                      /* '<S25>/sqrt' */
  real_T Switch_f[2];                  /* '<S32>/Switch' */
  real_T Product_n4;                   /* '<S32>/Product' */
  real_T Add_de;                       /* '<S31>/Add' */
  real_T Add_i;                        /* '<S29>/Add' */
  real_T Add_m;                        /* '<S30>/Add' */
  real_T Product_i[3];                 /* '<S25>/Product' */
  real_T Add_h;                        /* '<S43>/Add' */
  real_T sqrt_o2;                      /* '<S27>/sqrt' */
  real_T Add_b;                        /* '<S39>/Add' */
  real_T Add_a;                        /* '<S40>/Add' */
  real_T Add_p;                        /* '<S41>/Add' */
  real_T Switch_o[2];                  /* '<S42>/Switch' */
  real_T Product_ph;                   /* '<S42>/Product' */
  real_T Product_oe[3];                /* '<S27>/Product' */
  real_T Add_hm;                       /* '<S38>/Add' */
  real_T sqrt_p;                       /* '<S26>/sqrt' */
  real_T Add_o;                        /* '<S36>/Add' */
  real_T Add_f;                        /* '<S35>/Add' */
  real_T Add_b4;                       /* '<S34>/Add' */
  real_T Switch_f1[2];                 /* '<S37>/Switch' */
  real_T Product_jp;                   /* '<S37>/Product' */
  real_T Product_oi[3];                /* '<S26>/Product' */
  real_T Sum_dx;                       /* '<S22>/Sum' */
  real_T sqrt_b;                       /* '<S22>/sqrt' */
  real_T Gain1_lg;                     /* '<S22>/Gain1' */
  real_T Add_i5;                       /* '<S45>/Add' */
  real_T Add_fn;                       /* '<S44>/Add' */
  real_T Add_mp;                       /* '<S46>/Add' */
  boolean_T Compare;                   /* '<S79>/Compare' */
  boolean_T Compare_k;                 /* '<S80>/Compare' */
  boolean_T OR;                        /* '<S73>/OR' */
  boolean_T Compare_h;                 /* '<S112>/Compare' */
  boolean_T Compare_i;                 /* '<S127>/Compare' */
  boolean_T xz;                        /* '<S128>/x>z' */
  boolean_T Compare_j;                 /* '<S58>/Compare' */
  boolean_T Compare_n[9];              /* '<S56>/Compare' */
  boolean_T LogicalOperator1;          /* '<S50>/Logical Operator1' */
} B_asbCubeSatACS_c_T;

/* Block states (default storage) for model 'asbCubeSatACS' */
typedef struct {
  real_T Integrator_DSTATE[3];         /* '<S201>/Integrator' */
  real_T UD_DSTATE[3];                 /* '<S196>/UD' */
  void* Assertion_slioAccessor;        /* '<S52>/Assertion' */
  void* Assertion_slioAccessor_g;      /* '<S53>/Assertion' */
  void* Assertion_slioAccessor_n;      /* '<S54>/Assertion' */
  void* Assertion_slioAccessor_o;      /* '<S55>/Assertion' */
  uint8_T is_active_c1_asbCubeSatACS;  /* '<S1>/Pointing Mode Selection' */
  uint8_T is_c1_asbCubeSatACS;         /* '<S1>/Pointing Mode Selection' */
  uint8_T is_On;                       /* '<S1>/Pointing Mode Selection' */
} DW_asbCubeSatACS_f_T;

/* Invariant block signals for model 'asbCubeSatACS' */
typedef struct {
  const real_T DotProduct3;            /* '<S77>/Dot Product3' */
  const real_T DotProduct1;            /* '<S77>/Dot Product1' */
  const real_T DotProduct2;            /* '<S77>/Dot Product2' */
  const real_T Divide1;                /* '<S77>/Divide1' */
  const real_T Sqrt3;                  /* '<S77>/Sqrt3' */
  const real_T Divide;                 /* '<S77>/Divide' */
  const real_T Bias;                   /* '<S77>/Bias' */
  const real_T Abs;                    /* '<S77>/Abs' */
  const real_T Bias1;                  /* '<S77>/Bias1' */
  const real_T Abs1;                   /* '<S77>/Abs1' */
  const real_T DotProduct1_m;          /* '<S111>/Dot Product1' */
  const real_T DotProduct1_d;          /* '<S84>/Dot Product1' */
  const real_T Gain;                   /* '<S113>/Gain' */
  const real_T Gain2;                  /* '<S113>/Gain2' */
  const real_T Switch3[3];             /* '<S113>/Switch3' */
  const real_T ixj;                    /* '<S121>/i x j' */
  const real_T jxk;                    /* '<S121>/j x k' */
  const real_T kxi;                    /* '<S121>/k x i' */
  const real_T ixk;                    /* '<S122>/i x k' */
  const real_T jxi;                    /* '<S122>/j x i' */
  const real_T kxj;                    /* '<S122>/k x j' */
  const real_T Sum[3];                 /* '<S120>/Sum' */
  const real_T ixj_o;                  /* '<S142>/i x j' */
  const real_T jxk_h;                  /* '<S142>/j x k' */
  const real_T kxi_l;                  /* '<S142>/k x i' */
  const real_T ixk_m;                  /* '<S143>/i x k' */
  const real_T jxi_a;                  /* '<S143>/j x i' */
  const real_T kxj_f;                  /* '<S143>/k x j' */
  const real_T Sum_b[3];               /* '<S140>/Sum' */
  const real_T ixj_j;                  /* '<S144>/i x j' */
  const real_T jxk_l;                  /* '<S144>/j x k' */
  const real_T kxi_p;                  /* '<S144>/k x i' */
  const real_T ixk_me;                 /* '<S145>/i x k' */
  const real_T jxi_f;                  /* '<S145>/j x i' */
  const real_T kxj_g;                  /* '<S145>/k x j' */
  const real_T Sum_d[3];               /* '<S141>/Sum' */
  const boolean_T xz;                  /* '<S113>/x>z' */
} ConstB_asbCubeSatACS_h_T;

/* Real-time Model Data Structure */
struct tag_RTM_asbCubeSatACS_T {
  const char_T **errorStatus;
};

typedef struct {
  B_asbCubeSatACS_c_T rtb;
  DW_asbCubeSatACS_f_T rtdw;
  RT_MODEL_asbCubeSatACS_T rtm;
} MdlrefDW_asbCubeSatACS_T;

/* Model reference registration function */
extern void asbCubeSatACS_initialize(const char_T **rt_errorStatus,
  RT_MODEL_asbCubeSatACS_T *const asbCubeSatACS_M, B_asbCubeSatACS_c_T *localB,
  DW_asbCubeSatACS_f_T *localDW);
extern const StatesOutBus asbCubeSatACS_rtZStatesOutBus;/* StatesOutBus ground */
extern const EnvBus asbCubeSatACS_rtZEnvBus;/* EnvBus ground */
extern void asbCubeSatAC_IfActionSubsystem2(real_T rtu_In, real_T *rty_OutOrig);
extern void asbCubeSatACS_IfActionSubsystem(real_T *rty_Out1);
extern void asbCubeSatAC_IfActionSubsystem1(real_T *rty_Out1);
extern void asbCubeSat_IfActionSubsystem2_j(real_T *rty_Out1);
extern void asbCubeSatACS_Init(ACSOutBus *rty_ACSOut, B_asbCubeSatACS_c_T
  *localB, DW_asbCubeSatACS_f_T *localDW);
extern void asbCubeSatACS_Reset(B_asbCubeSatACS_c_T *localB,
  DW_asbCubeSatACS_f_T *localDW);
extern void asbCubeSatACS_Update(B_asbCubeSatACS_c_T *localB,
  DW_asbCubeSatACS_f_T *localDW);
extern void asbCubeSatACS(const real_T rtu_SensorsOut_V_ecef[3], const real_T
  rtu_SensorsOut_X_ecef[3], const real_T rtu_SensorsOut_q_ecef2b[4], const
  real_T rtu_SensorsOut_q_eci2b[4], const real_T rtu_SensorsOut_Euler[3], const
  real_T rtu_SensorsOut_LatLonAlt[3], const real_T rtu_SensorsOut_x_sun_eci[3],
  const real_T *rtu_AttitudeMode, const real_T rtu_Environment_envForces_body[3],
  const real_T rtu_Environment_envTorques_body[3], const real_T
  rtu_Environment_x_sun_eci[3], const real_T *rtu_Environment_earthAngRate,
  ACSOutBus *rty_ACSOut, B_asbCubeSatACS_c_T *localB, DW_asbCubeSatACS_f_T
  *localDW);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'asbCubeSatACS'
 * '<S1>'   : 'asbCubeSatACS/Attitude Control'
 * '<S2>'   : 'asbCubeSatACS/Discrete PID Controller'
 * '<S3>'   : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection'
 * '<S4>'   : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/Off'
 * '<S5>'   : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth'
 * '<S6>'   : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun'
 * '<S7>'   : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF'
 * '<S8>'   : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternion Inverse'
 * '<S9>'   : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternion Multiplication'
 * '<S10>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternions to Rotation Angles'
 * '<S11>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/3x3 Cross Product'
 * '<S12>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/3x3 Cross Product1'
 * '<S13>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions'
 * '<S14>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/vnorm'
 * '<S15>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/vnorm1'
 * '<S16>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/vnorm2'
 * '<S17>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/3x3 Cross Product/Subsystem'
 * '<S18>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/3x3 Cross Product/Subsystem1'
 * '<S19>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/3x3 Cross Product1/Subsystem'
 * '<S20>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/3x3 Cross Product1/Subsystem1'
 * '<S21>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace'
 * '<S22>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Positive Trace'
 * '<S23>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM'
 * '<S24>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/trace(DCM)'
 * '<S25>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S26>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S27>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S28>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/diag(DCM)'
 * '<S29>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S30>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S31>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S32>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S33>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S34>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S35>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S36>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S37>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S38>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S39>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S40>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S41>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S42>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S43>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S44>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S45>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S46>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S47>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error'
 * '<S48>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal'
 * '<S49>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper'
 * '<S50>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal'
 * '<S51>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper'
 * '<S52>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
 * '<S53>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
 * '<S54>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Error'
 * '<S55>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Warning'
 * '<S56>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
 * '<S57>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
 * '<S58>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Calculate Quaternion ECEF to ORF/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
 * '<S59>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternion Inverse/Quaternion Conjugate'
 * '<S60>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternion Inverse/Quaternion Norm'
 * '<S61>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternion Multiplication/q0'
 * '<S62>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternion Multiplication/q1'
 * '<S63>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternion Multiplication/q2'
 * '<S64>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternion Multiplication/q3'
 * '<S65>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternions to Rotation Angles/Angle Calculation'
 * '<S66>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternions to Rotation Angles/Quaternion Normalize'
 * '<S67>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
 * '<S68>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
 * '<S69>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
 * '<S70>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
 * '<S71>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
 * '<S72>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Earth/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S73>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command'
 * '<S74>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation'
 * '<S75>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation1'
 * '<S76>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternions to Rotation Angles1'
 * '<S77>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Check Parallel'
 * '<S78>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Check Parallel1'
 * '<S79>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Compare To Zero'
 * '<S80>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Compare To Zero1'
 * '<S81>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Multiplication2'
 * '<S82>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation1'
 * '<S83>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation5'
 * '<S84>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b'
 * '<S85>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1'
 * '<S86>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection'
 * '<S87>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection1'
 * '<S88>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Check Parallel/If Action Subsystem'
 * '<S89>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Check Parallel/If Action Subsystem1'
 * '<S90>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Check Parallel/If Action Subsystem2'
 * '<S91>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Check Parallel1/If Action Subsystem'
 * '<S92>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Check Parallel1/If Action Subsystem1'
 * '<S93>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Check Parallel1/If Action Subsystem2'
 * '<S94>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Multiplication2/q0'
 * '<S95>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Multiplication2/q1'
 * '<S96>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Multiplication2/q2'
 * '<S97>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Multiplication2/q3'
 * '<S98>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation1/Quaternion Normalize'
 * '<S99>'  : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation1/V1'
 * '<S100>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation1/V2'
 * '<S101>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation1/V3'
 * '<S102>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
 * '<S103>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S104>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation5/Quaternion Normalize'
 * '<S105>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation5/V1'
 * '<S106>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation5/V2'
 * '<S107>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation5/V3'
 * '<S108>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation5/Quaternion Normalize/Quaternion Modulus'
 * '<S109>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion Rotation5/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S110>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/3x3 Cross Product2'
 * '<S111>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Check Parallel'
 * '<S112>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Compare To Constant'
 * '<S113>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Find Orthogonal'
 * '<S114>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Quaternion Normalize2'
 * '<S115>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/3x3 Cross Product2/Subsystem'
 * '<S116>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/3x3 Cross Product2/Subsystem1'
 * '<S117>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Check Parallel/If Action Subsystem'
 * '<S118>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Check Parallel/If Action Subsystem1'
 * '<S119>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Check Parallel/If Action Subsystem2'
 * '<S120>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Find Orthogonal/3x3 Cross Product'
 * '<S121>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Find Orthogonal/3x3 Cross Product/Subsystem'
 * '<S122>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Find Orthogonal/3x3 Cross Product/Subsystem1'
 * '<S123>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Quaternion Normalize2/Quaternion Modulus'
 * '<S124>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b/Quaternion Normalize2/Quaternion Modulus/Quaternion Norm'
 * '<S125>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/3x3 Cross Product2'
 * '<S126>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Check Parallel'
 * '<S127>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Compare To Constant'
 * '<S128>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Find Orthogonal'
 * '<S129>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Quaternion Normalize2'
 * '<S130>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/3x3 Cross Product2/Subsystem'
 * '<S131>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/3x3 Cross Product2/Subsystem1'
 * '<S132>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Check Parallel/If Action Subsystem'
 * '<S133>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Check Parallel/If Action Subsystem1'
 * '<S134>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Check Parallel/If Action Subsystem2'
 * '<S135>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Find Orthogonal/3x3 Cross Product'
 * '<S136>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Find Orthogonal/3x3 Cross Product/Subsystem'
 * '<S137>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Find Orthogonal/3x3 Cross Product/Subsystem1'
 * '<S138>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Quaternion Normalize2/Quaternion Modulus'
 * '<S139>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Quaternion between r_a and r_b1/Quaternion Normalize2/Quaternion Modulus/Quaternion Norm'
 * '<S140>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection/3x3 Cross Product1'
 * '<S141>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection/3x3 Cross Product2'
 * '<S142>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection/3x3 Cross Product1/Subsystem'
 * '<S143>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection/3x3 Cross Product1/Subsystem1'
 * '<S144>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection/3x3 Cross Product2/Subsystem'
 * '<S145>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection/3x3 Cross Product2/Subsystem1'
 * '<S146>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection1/3x3 Cross Product1'
 * '<S147>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection1/3x3 Cross Product2'
 * '<S148>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection1/3x3 Cross Product1/Subsystem'
 * '<S149>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection1/3x3 Cross Product1/Subsystem1'
 * '<S150>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection1/3x3 Cross Product2/Subsystem'
 * '<S151>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Compute Attitude Command/Vector Projection1/3x3 Cross Product2/Subsystem1'
 * '<S152>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation/Quaternion Normalize'
 * '<S153>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation/V1'
 * '<S154>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation/V2'
 * '<S155>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation/V3'
 * '<S156>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S157>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S158>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation1/Quaternion Normalize'
 * '<S159>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation1/V1'
 * '<S160>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation1/V2'
 * '<S161>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation1/V3'
 * '<S162>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
 * '<S163>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S164>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternions to Rotation Angles1/Angle Calculation'
 * '<S165>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternions to Rotation Angles1/Quaternion Normalize'
 * '<S166>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input'
 * '<S167>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input/If Action Subsystem'
 * '<S168>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input/If Action Subsystem1'
 * '<S169>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input/If Action Subsystem2'
 * '<S170>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternions to Rotation Angles1/Quaternion Normalize/Quaternion Modulus'
 * '<S171>' : 'asbCubeSatACS/Attitude Control/Pointing Mode Selection/On.Sun/Quaternions to Rotation Angles1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S172>' : 'asbCubeSatACS/Discrete PID Controller/Anti-windup'
 * '<S173>' : 'asbCubeSatACS/Discrete PID Controller/D Gain'
 * '<S174>' : 'asbCubeSatACS/Discrete PID Controller/Filter'
 * '<S175>' : 'asbCubeSatACS/Discrete PID Controller/Filter ICs'
 * '<S176>' : 'asbCubeSatACS/Discrete PID Controller/I Gain'
 * '<S177>' : 'asbCubeSatACS/Discrete PID Controller/Ideal P Gain'
 * '<S178>' : 'asbCubeSatACS/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S179>' : 'asbCubeSatACS/Discrete PID Controller/Integrator'
 * '<S180>' : 'asbCubeSatACS/Discrete PID Controller/Integrator ICs'
 * '<S181>' : 'asbCubeSatACS/Discrete PID Controller/N Copy'
 * '<S182>' : 'asbCubeSatACS/Discrete PID Controller/N Gain'
 * '<S183>' : 'asbCubeSatACS/Discrete PID Controller/P Copy'
 * '<S184>' : 'asbCubeSatACS/Discrete PID Controller/Parallel P Gain'
 * '<S185>' : 'asbCubeSatACS/Discrete PID Controller/Reset Signal'
 * '<S186>' : 'asbCubeSatACS/Discrete PID Controller/Saturation'
 * '<S187>' : 'asbCubeSatACS/Discrete PID Controller/Saturation Fdbk'
 * '<S188>' : 'asbCubeSatACS/Discrete PID Controller/Sum'
 * '<S189>' : 'asbCubeSatACS/Discrete PID Controller/Sum Fdbk'
 * '<S190>' : 'asbCubeSatACS/Discrete PID Controller/Tracking Mode'
 * '<S191>' : 'asbCubeSatACS/Discrete PID Controller/Tracking Mode Sum'
 * '<S192>' : 'asbCubeSatACS/Discrete PID Controller/postSat Signal'
 * '<S193>' : 'asbCubeSatACS/Discrete PID Controller/preSat Signal'
 * '<S194>' : 'asbCubeSatACS/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S195>' : 'asbCubeSatACS/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S196>' : 'asbCubeSatACS/Discrete PID Controller/Filter/Differentiator'
 * '<S197>' : 'asbCubeSatACS/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S198>' : 'asbCubeSatACS/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S199>' : 'asbCubeSatACS/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S200>' : 'asbCubeSatACS/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S201>' : 'asbCubeSatACS/Discrete PID Controller/Integrator/Discrete'
 * '<S202>' : 'asbCubeSatACS/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S203>' : 'asbCubeSatACS/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S204>' : 'asbCubeSatACS/Discrete PID Controller/N Gain/Passthrough'
 * '<S205>' : 'asbCubeSatACS/Discrete PID Controller/P Copy/Disabled'
 * '<S206>' : 'asbCubeSatACS/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S207>' : 'asbCubeSatACS/Discrete PID Controller/Reset Signal/Disabled'
 * '<S208>' : 'asbCubeSatACS/Discrete PID Controller/Saturation/Passthrough'
 * '<S209>' : 'asbCubeSatACS/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S210>' : 'asbCubeSatACS/Discrete PID Controller/Sum/Sum_PID'
 * '<S211>' : 'asbCubeSatACS/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S212>' : 'asbCubeSatACS/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S213>' : 'asbCubeSatACS/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S214>' : 'asbCubeSatACS/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S215>' : 'asbCubeSatACS/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_asbCubeSatACS_h_ */
