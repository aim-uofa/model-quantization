
dataset='cifar100'
root=$FASTDIR/data/cifar

model='resnet20'
options="$options --width_alpha 0.25"

train_batch=128
val_batch=50

case='cifar100-ldq-lsq-finetune-2bit-pytorch-order_c-wd1e-4-wt_qg1_var-mean-real_skip-sgd_0'
keyword='cifar100,origin,cbsa,fix_pooling,singleconv,fix,ReShapeResolution,real_skip,dorefa,lsq'

pretrained='cifar100-ldn-scratch-fp-pytorch-order_c-wd1e-4-sgd_0-model_best.pth.tar'
options="$options --pretrained $pretrained"

 options="$options --tensorboard"
 options="$options --verbose"
#options="$options -j2"
#options="$options -e"
#options="$options -r"
#options="$options --fp16 --opt_level O1"
 options="$options --wd 1e-4"
 options="$options --decay_small"
 options="$options --order c"

 options="$options --fm_bit 2 --fm_enable"
 options="$options --wt_bit 2 --wt_enable"
 options="$options --fm_quant_group 1"
 options="$options --wt_quant_group 1"
 options="$options --wt_adaptive var-mean"

 epochs=200
# SGD
 options="$options --lr 1e-2 --lr_policy custom_step --lr_decay 0.2 --lr_custom_step 60,120,160 --nesterov"
